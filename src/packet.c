/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:45:55 by ygarrot           #+#    #+#             */
/*   Updated: 2019/07/09 19:10:14 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int set_packet(t_ping *ping)
{
	static int ttl = 1;
	struct ip *iph = (struct ip *) ping->packet;
	struct icmphdr *icmph = (struct icmphdr*)(ping->packet + sizeof(struct ip));

	iph->ip_hl = 5;
	iph->ip_v = 4;
	iph->ip_tos = 0;
	iph->ip_len = htons(sizeof(struct ip) + sizeof(struct icmphdr));
	iph->ip_id = htons(getpid() & 0xff);
	iph->ip_off = 0;
	iph->ip_ttl = htons(ttl);
	iph->ip_p = IPPROTO_ICMP;
	/* if (inet_pton (AF_INET, "172.17.0.2", &(iph->ip_src)) <=0) */
	/* 	perror("inet_pton1\n"); */
	/* inet_pton (AF_INET, "192.168.1.168", &(iph->ip_src)); */
	/* iph->ip_src.s_addr = INADDR_ANY; */
	if (inet_pton (AF_INET, ping->host_addr, &(iph->ip_dst))==0)
		perror("inet_pton2\n");

	icmph->type = ICMP_ECHO;
	icmph->code = 0;
	/* icmph->un.echo.id = htons(getpid()); */
	/* icmph->un.echo.sequence = htons(ttl + 1); */

	iph->ip_sum = checksum(iph, sizeof(struct ip));
	icmph->checksum = checksum(icmph, sizeof(struct icmphdr));
	++ttl;
	/* printf("%d\n", ((struct ip*)ping->packet)->ip_hl); */
	/* printf("%d\n", iph->ip_v); */
	/* printf("%d\n", iph->ip_tos); */
	/* printf("%d\n", iph->ip_len); */
	/* printf("%d\n", iph->ip_id); */
	/* printf("%d\n", iph->ip_off); */
	/* printf("%d\n", iph->ip_ttl); */
	return (1);
}
