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
	return (1);
}

suseconds_t			get_time(struct timeval curr_time)
{
	return (curr_time.tv_sec * 1000000 + curr_time.tv_usec);
}


int		recv_ping(t_ping *ping, char *buff, int sockfd)
{
	static int 		first_ttl = -1;
	struct sockaddr_in	from;
	socklen_t		from_len;
	struct icmphdr		*icmph;
	struct ip		*fr;

	int ttl;
	int icmp_type;
	gettimeofday(&ping->env.time, 0);
	if (first_ttl == -1)
		first_ttl = ping->env.max_ttl;
	from_len = sizeof(struct sockaddr_in);
	if (recvfrom(sockfd, buff, RECV_PACKET_SIZE, 0, (struct sockaddr*)&from, &from_len) == ERROR_CODE)
	{
		printf("Packet receive failed!\n");
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
	/* ft_printf("%d\n", */ 
	/* ping->route[ntohs(icmph->un.echo.id)].done); */
	if (ttl > first_ttl)
		return(1);
	ping->route[ntohs(icmph->un.echo.id)].tries[ntohs(icmph->un.echo.sequence)].tv_sec -= ping->env.time.tv_sec;
	ping->route[ntohs(icmph->un.echo.id)].tries[ntohs(icmph->un.echo.sequence)].tv_usec -= ping->env.time.tv_usec;
	ping->route[ttl].done++;
	ping->route[ttl].addr = ft_strdup(inet_ntoa(fr->ip_src)); 
	(void)fr;
	return (1);
}

int		ping_receive(int sockfd, t_ping *ping)
{
	fd_set			rdfds;
	int			i;
	char			buff[RECV_PACKET_SIZE] = { 0 };
	struct			timeval tv_out = {
		.tv_sec = ping->env.timeout,
		.tv_usec = 0
	};

	i = -1;
	while (++i < ping->env.max_ttl * ping->env.max_tries)
	{
		FD_ZERO(&rdfds);
		FD_SET(sockfd, &rdfds);
		if (select(sockfd + 1, &rdfds, NULL, NULL, &tv_out) == ERROR_CODE)
			ft_exit("select failed\n", EXIT_FAILURE);
		if (FD_ISSET(sockfd, &rdfds))
		{
			recv_ping(ping, buff, sockfd);
			print_foreach(ping);
		}
	}
	return (1);
}
