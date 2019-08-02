/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:45:55 by ygarrot           #+#    #+#             */
/*   Updated: 2019/07/30 09:33:19 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int set_ip_struct(t_ping *ping)
{
	struct ip *iph = (struct ip *) ping->packet;

	iph->ip_hl = 5;
	iph->ip_v = 4;
	iph->ip_tos = 0;
	iph->ip_len = htons(SENT_PACKET_SIZE);
	iph->ip_id = htons(getpid() & 0xff);
	iph->ip_off = 0;
	iph->ip_ttl = htons(ping->ttl);
	iph->ip_p = IPPROTO_ICMP;
	iph->ip_src.s_addr = INADDR_ANY;
	iph->ip_dst.s_addr = ping->des;
	/* iph->ip_sum = in_cksum(iph, sizeof(struct ip)); */
	return (1);
}

int set_icmp_struct(t_ping *ping)
{
	struct icmphdr *icmph = (struct icmphdr*)(ping->packet + sizeof(struct ip));

	icmph->type = ICMP_ECHO;
	icmph->code = 0;
	icmph->un.echo.id = htons(ping->queries);
	icmph->un.echo.sequence = htons(ping->ttl);
	icmph->checksum = in_cksum((unsigned short*)icmph, sizeof(struct icmphdr) + PAYLOAD_SIZE);
	/* printf("%d\n", ((struct ip*)ping->packet)->ip_hl); */
	/* printf("%d\n", iph->ip_v); */
	/* printf("%d\n", iph->ip_tos); */
	/* printf("%d\n", iph->ip_len); */
	/* printf("%d\n", iph->ip_id); */
	/* printf("%d\n", iph->ip_off); */
	/* printf("%d\n", iph->ip_ttl); */
	return (1);
}

int set_packet(t_ping *ping)
{
	set_ip_struct(ping);
	memset(ping->packet + sizeof(struct icmphdr), 42, PAYLOAD_SIZE);
	set_icmp_struct(ping);
	return (1);
}
