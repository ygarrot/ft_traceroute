/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:53:58 by ygarrot           #+#    #+#             */
/*   Updated: 2019/07/14 14:06:36 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int		ping_send(int socket, t_ping *ping)
{
	if (sendto(socket, ping->packet,
			SENT_PACKET_SIZE,
				0,
				(struct sockaddr*)ping->sockaddr,
				sizeof(struct sockaddr_in)) <= 0)
	{
		ft_exit("connect: invalid argument", EXIT_FAILURE);
		return (ERROR_CODE);
	}
	ping->pstat.send++;
	return (1);
}

int		recv_ping(t_ping *ping, char *buff, int sockfd)
{
	static int 		first_ttl = TRC_MAX_TTL - 1;
	struct sockaddr_in	from;
	socklen_t		from_len;
	struct icmphdr		*icmph;
	struct ip		*fr;

	int ttl;
	int icmp_type;

	from_len = sizeof(struct sockaddr_in);
	if (recvfrom(sockfd, buff, RECV_PACKET_SIZE, 0, (struct sockaddr*)&from, &from_len) == ERROR_CODE)
	{
		ft_printf("Packet receive failed!\n");
		return (ERROR_CODE);
	}
	icmph = (struct icmphdr*)(buff + sizeof(struct ip));
	icmp_type = icmph->type;
	if (icmp_type == ICMP_TIME_EXCEEDED)
		icmph = (struct icmphdr*)(buff + 2 * IP_HDR_SIZE + ICMP_HDR_SIZE);
	ttl = ntohs(icmph->un.echo.id);
	fr = (struct ip*)buff;
	if (icmp_type == ICMP_ECHOREPLY)
	{
		if (ttl < first_ttl)
			first_ttl = ttl;
	}
	if (ttl > first_ttl)
		return(1);
	ft_printf("[%s] -> ", inet_ntoa(fr->ip_src));
	/* ft_printf("{boldred}struct icmph:"); */
	/* ft_printf(" code: %d", icmph->code); */
	ft_printf(" ttl: %d", ntohs(icmph->un.echo.id));
	ft_printf(" sequence: %d", ntohs(icmph->un.echo.sequence));
	/* ft_printf("{boldblue}struct ip:"); */
	/* ft_printf("hl: %d", fr->ip_hl); */
	/* ft_printf("version: %d", fr->ip_v); */
	/* ft_printf(" tos: %d", fr->ip_tos); */
	/* ft_printf(" len: %d", fr->ip_len); */
	/* ft_printf(" id: %d", fr->ip_id); */
	/* ft_printf(" off: %d", fr->ip_off); */
	/* ft_printf(" ttl: %d\n", fr->ip_ttl); */
	ft_putendl("");
	ping->pstat.rcv++;
	return (1);
}

int		ping_receive(int sockfd, t_ping *ping)
{
	fd_set			rdfds;
	int			i;
	char			buff[RECV_PACKET_SIZE] = { 0 };
	struct			timeval tv_out = {
		.tv_sec = ping->tstat.timeout,
	};

	i = -1;
	while (++i < TRC_MAX_TTL * TRC_QUERIES)
	{
		FD_ZERO(&rdfds);
		FD_SET(sockfd, &rdfds);
		if (select(sockfd + 1, &rdfds, NULL, NULL, &tv_out) == ERROR_CODE)
			ft_exit("select failed\n", EXIT_FAILURE);
		if (FD_ISSET(sockfd, &rdfds))
		{
			recv_ping(ping, buff, sockfd);
		}
	}
	return (1);
}
