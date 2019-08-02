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
				ping->sockaddr_len) <= 0)
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
	char buff[BUFF_S] = { 0 };
	socklen_t		from_len;
	struct timeval tv_out;
	fd_set rdfds;

	/* tv_out.tv_sec = ping->tstat.timeout; */
	tv_out.tv_sec = 3;
	tv_out.tv_usec = 0;

	from_len = sizeof(struct sockaddr_in);
	int i = -1;
	while (++i < 30 * 3)
	{
		FD_ZERO(&rdfds);
		FD_SET(sockfd, &rdfds);
		if (select(sockfd + 1, &rdfds, 0, 0, &tv_out) < 0)
			ft_exit("select failed\n", EXIT_FAILURE);
		if (FD_ISSET(sockfd, &rdfds))
		{
			if (recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr*)&from, &from_len) < 0)
			{
				perror("recv");
				ft_printf("Packet receive failed!\n");
				return (ERROR_CODE);
			}
			struct icmphdr *icmph = (struct icmphdr*)(buff + 20);
			if (icmph->type == 0)
				exit(0);
			struct ip *fr = (struct ip*)buff;
			char *ip = inet_ntoa(fr->ip_src); 
			printf("[%s]\n", ip);
			ping->pstat.rcv++;
			/* break ; */
		}
	}
	return (1);
}
