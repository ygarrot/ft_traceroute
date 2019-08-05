/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:45:55 by ygarrot           #+#    #+#             */
/*   Updated: 2019/08/05 10:44:27 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int	set_ip_struct(t_ping *ping)
{
	struct ip *iph;

	iph = (struct ip *)ping->packet;
	iph->ip_hl = 5;
	iph->ip_v = 4;
	iph->ip_tos = ping->env.tos;
	iph->ip_len = SENT_PACKET_SIZE;
	iph->ip_id = htons(getpid() & 0xff);
	iph->ip_id = htons(0);
	iph->ip_off = 0;
	iph->ip_ttl = ping->env.ttl;
	iph->ip_p = IPPROTO_ICMP;
	iph->ip_sum = 0;
	iph->ip_src.s_addr = INADDR_ANY;
	iph->ip_dst.s_addr = ping->des;
	return (1);
}

int	set_icmp_struct(t_ping *ping)
{
	struct icmphdr *icmph;

	icmph = (struct icmphdr*)(ping->packet + sizeof(struct ip));
	icmph->type = ICMP_ECHO;
	icmph->code = 0;
	icmph->un.echo.id = htons(ping->env.ttl);
	icmph->un.echo.sequence = htons(ping->env.tries);
	icmph->checksum = 0;
	icmph->checksum =
		in_cksum((unsigned short*)icmph, sizeof(struct icmphdr));
	return (1);
}

int	set_packet(t_ping *ping)
{
	set_ip_struct(ping);
	set_icmp_struct(ping);
	return (1);
}
