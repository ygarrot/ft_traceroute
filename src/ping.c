/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:53:58 by ygarrot           #+#    #+#             */
/*   Updated: 2019/08/05 11:10:57 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int		ping_send(int socket, t_ping *ping)
{
	if (sendto(
				socket,
				ping->packet,
				SENT_PACKET_SIZE,
				0,
				(struct sockaddr*)ping->sockaddr,
				sizeof(struct sockaddr_in)) <= 0)
	{
		ft_exit("traceroute: sendto: Invalid argument", EXIT_FAILURE);
		;
	}
	return (1);
}

int		set_data(t_ping *ping, char *buff, struct icmphdr *icmph)
{
	struct ip	*ip;
	int			seq;
	int			ttl;

	ip = (struct ip*)buff;
	if (icmph->type == 0
	&& (ping->des != ip->ip_src.s_addr || (ping->last_ttl != -1
	&& ping->route[ping->last_ttl].done[ping->env.max_tries - 1])))
		return (1);
	if (icmph->type != 0)
		icmph = (struct icmphdr*)(buff
				+ 2 * sizeof(struct ip) + sizeof(struct icmphdr));
	ttl = ntohs(icmph->un.echo.id);
	seq = ntohs(icmph->un.echo.sequence);
	if (ip->ip_src.s_addr == ping->des)
		ping->last_ttl = ttl;
	if (!ping->route[ttl].addr)
		ping->route[ttl].addr = ft_strdup(inet_ntoa(ip->ip_src));
	if (ttl > ping->env.max_ttl || ttl < 0
	|| seq > ping->env.max_tries || seq < 0)
		return (1);
	ping->route[ttl].done[seq] = 1;
	ping->route[ttl].tries[seq].tv_sec -= ping->env.time.tv_sec;
	ping->route[ttl].tries[seq].tv_usec -= ping->env.time.tv_usec;
	return (1);
}

int		recv_ping(t_ping *ping, int sockfd)
{
	struct sockaddr		from;
	char				buff[RECV_PACKET_SIZE];
	socklen_t			from_len;

	gettimeofday(&ping->env.time, 0);
	from_len = sizeof(struct sockaddr);
	if (recvfrom(sockfd, buff, RECV_PACKET_SIZE, 0, &from, &from_len)
			== ERROR_CODE)
	{
		printf("Packet receive failed!\n");
		return (ERROR_CODE);
	}
	set_data(ping, buff, (struct icmphdr*)(buff + sizeof(struct ip)));
	return (1);
}

int		ping_receive(int sockfd, t_ping *ping)
{
	struct timeval	tv_out;
	fd_set			rdfds;

	tv_out = (struct timeval){
		.tv_sec = ping->env.timeout,
		.tv_usec = 0
	};
	if (ping->done)
		return (2);
	FD_ZERO(&rdfds);
	FD_SET(sockfd, &rdfds);
	ping->timedout = select(sockfd + 1, &rdfds, NULL, NULL, &tv_out);
	if (ping->timedout == ERROR_CODE)
		ft_exit("select failed\n", EXIT_FAILURE);
	if (!FD_ISSET(sockfd, &rdfds))
		return (1);
	recv_ping(ping, sockfd);
	return (1);
}
