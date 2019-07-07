/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:45:55 by ygarrot           #+#    #+#             */
/*   Updated: 2019/07/07 12:31:41 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int set_packet(t_ping *ping)
{
	static int ttl= 1;
	struct ip *iph = (struct ip *) ping->packet;
	struct icmphdr *icmph = (struct icmphdr*)(ping->packet + sizeof(struct ip));

	iph = &(struct ip){
		.ip_hl = 5,
	.ip_v = 4,
	.ip_tos = 0,
	.ip_len = htons(sizeof(struct ip) + sizeof(struct icmphdr)),
	.ip_id = htons(getpid() & 0xffff),
	.ip_off = 0,
	.ip_ttl = ttl,
	.ip_p = IPPROTO_ICMP,
	};
	inet_pton (AF_INET, "192.168.1.168", &(iph->ip_src));
	inet_pton (AF_INET, ping->host_name, &(iph->ip_dst));

	icmph = &(struct icmphdr){
	.type = ICMP_ECHO,
	.code = 0,
	/* .un.echo.id = getpid(), */
	.un.echo.sequence = ttl + 1,
		};
	iph->ip_sum = checksum(ping->packet, sizeof(struct ip));
	icmph->checksum = checksum (icmph, sizeof(struct icmphdr));
	++ttl;
	return (1);
}
