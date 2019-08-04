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
	if (sendto(
				socket,
				ping->packet,
				SENT_PACKET_SIZE,
				0,
				(struct sockaddr*)ping->sockaddr,
				sizeof(struct sockaddr_in)
		  ) <= 0)
	{
		ft_exit("connect: invalid argument", EXIT_FAILURE);
	}
	return (1);
}

int		set_data(t_ping *ping, char *buff, struct icmphdr *icmph)
{
	int			seq;
	struct 			ip *ip;
	int			ttl;

	ip = (struct ip*)buff;
	if (icmph->type == 0
	&& (ping->des != ip->ip_src.s_addr || (ping->last_ttl != -1
	&& ping->route[ping->last_ttl].done >= ping->env.max_tries)))
		return (1);
	if (icmph->type != 0)
		icmph = (struct icmphdr*)(buff + 2 * IP_HDR_SIZE + ICMP_HDR_SIZE);
	ttl = ntohs(icmph->un.echo.id);
	seq = ntohs(icmph->un.echo.sequence);
	if (ping->last_ttl == -1 && ip->ip_src.s_addr == ping->des)
		ping->last_ttl = ttl;
	if (!ping->route[ttl].addr) 
		ping->route[ttl].addr = ft_strdup(inet_ntoa(ip->ip_src)); 
	ping->route[ttl].tries[seq].tv_sec -= ping->env.time.tv_sec;
	ping->route[ttl].tries[seq].tv_usec -= ping->env.time.tv_usec;
	ping->route[ttl].done++;
	return (1);
}

int		recv_ping(t_ping *ping, int sockfd)
{
	struct sockaddr		from;
	char			buff[RECV_PACKET_SIZE] = { 0 };
	socklen_t		from_len;

	gettimeofday(&ping->env.time, 0);
	from_len = sizeof(struct sockaddr);
	if (recvfrom(sockfd, buff, RECV_PACKET_SIZE, 0, &from, &from_len) == ERROR_CODE)
	{
		printf("Packet receive failed!\n");
		return (ERROR_CODE);
	}
	set_data(ping, buff, (struct icmphdr*)(buff + sizeof(struct ip)));
	return (1);
}

int		ping_receive(int sockfd, t_ping *ping, int i)
{
	fd_set			rdfds;
	struct		timeval tv_out = {
		.tv_sec = ping->env.timeout,
		.tv_usec = 0
	};

	if (ping->done || i >= ping->env.max_ttl * ping->env.max_tries)
		return (1);
	FD_ZERO(&rdfds);
	FD_SET(sockfd, &rdfds);
	if (select(sockfd + 1, &rdfds, NULL, NULL, &tv_out) == ERROR_CODE)
		ft_exit("select failed\n", EXIT_FAILURE);
	if (!FD_ISSET(sockfd, &rdfds))
		return (ping_receive(sockfd, ping, ++i));
	recv_ping(ping, sockfd);
	print_foreach(ping);
	return (ping_receive(sockfd, ping, ++i));
}
