/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:45:55 by ygarrot           #+#    #+#             */
/*   Updated: 2019/07/02 17:07:20 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int set_packet(t_packet *pckt, t_ping *ping)
{
	/* struct ip *iph = (struct ip *) buffer; */
	/* pckt.icmphd = (struct icmphdr*)(buffer + sizeof(struct ip)); */
	pckt->iph = (struct ip){
		.ip_hl = 5,
	.ip_v = 4,
	.ip_tos = 0,
	.ip_len = sizeof(struct ip) + sizeof(struct icmphdr),
	.ip_id = getpid(),
	.ip_off = 0,
	.ip_ttl = 0,
	.ip_p = 6,
	.ip_sum = checksum(pckt, sizeof(struct ip)),
	};
	inet_pton (AF_INET, ping->host_name, &(pckt->iph.ip_dst));
	pckt->icmph = (struct icmphdr){
	.type = ICMP_ECHO,
	.code = 0,
	.un.echo.id = getpid(),
	.un.echo.sequence = 1,
	.checksum = checksum (pckt + sizeof(struct ip), sizeof(struct icmphdr)),
			};
	return (1);
}


/* int		set_packet(t_packet *pckt, t_ping *ping) */
/* { */
/* 	static int	msg_count = 0; */
/* 	int			i; */

/* 	i = -1; */
/* 	ft_bzero(pckt, sizeof(t_packet)); */
/* 	pckt->hdr.type = ICMP_ECHO; */
/* 	pckt->hdr.un.echo.id = getpid(); */
/* 	while (++i < ping->pstat.size - 1) */
/* 		pckt->msg[i] = i + '0'; */
/* 	pckt->msg[i] = 0; */
/* 	pckt->hdr.un.echo.sequence = msg_count++; */
/* 	pckt->hdr.checksum = checksum(pckt, sizeof(t_packet)); */
/* 	return (1); */
/* } */
