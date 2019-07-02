/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:53:58 by ygarrot           #+#    #+#             */
/*   Updated: 2019/07/02 17:09:18 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int		ping_send(t_packet *pckt, int socket, t_ping *ping)
{
	if (sendto(socket, pckt,
				sizeof(t_packet),
				0,
				(t_sockaddr*)ping->sockaddr,
				ping->sockaddr_len) <= 0)
	{
		ft_exit("connect: invalid argument", 1);
		return (ERROR_CODE);
	}
	ping->pstat.send++;
	return (1);
}

int		ping_receive(int sockfd, t_ping *ping)
{
	struct sockaddr_in	from;
	char buff[BUFF_S] = { 0 };
	unsigned int		from_len;

	from_len = sizeof(from);
	if (recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr*)&from, &from_len) < 0)
	{
		ft_printf("Packet receive failed!\n");
		return (ERROR_CODE);
	}
	printf("%s\n", inet_ntoa(from.sin_addr));
	ping->pstat.rcv++;
	return (1);
}
