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

int		ping_receive(int sockfd, t_ping *ping)
{
	struct sockaddr_in	from;
	socklen_t		from_len;
	char buff[RECV_PACKET_SIZE] = { 0 };
	struct timeval tv_out = {
		.tv_sec = SELECT_TIMEOUT,
	};
	fd_set rdfds;

	/* tv_out.tv_sec = ping->tstat.timeout; */
	from_len = sizeof(struct sockaddr_in);
	int i = -1;
	while (++i < TRC_MAX_TTL * TRC_QUERIES)
	{
		FD_ZERO(&rdfds);
		FD_SET(sockfd, &rdfds);
		if (select(sockfd + 1, &rdfds, NULL, NULL, &tv_out) == ERROR_CODE)
			ft_exit("select failed\n", EXIT_FAILURE);
		if (FD_ISSET(sockfd, &rdfds))
		{
			if (recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr*)&from, &from_len) < 0)
			{
				perror("recv");
				ft_printf("Packet receive failed!\n");
				return (ERROR_CODE);
			}
			/* struct icmphdr *icmph = (struct icmphdr*)(buff + 20); */
			/* if (icmph->type == 0) */
			/* 	exit(0); */
			struct ip *fr = (struct ip*)buff;
			char *ip = inet_ntoa(fr->ip_src); 
			printf("[%s]\n", ip);
			ping->pstat.rcv++;
		}
	}
	return (1);
}
