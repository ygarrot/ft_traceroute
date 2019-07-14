/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:56:47 by ygarrot           #+#    #+#             */
/*   Updated: 2019/07/14 14:06:36 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

int	print_ping(t_ping *ping)
{
	printf("%ld bytes from ", sizeof(ping->packet));
	if (ping->opt & NUMERIC)
		printf("%s:", ping->host_addr);
	else
		printf("%s (%s):", ping->dns_addr, ping->host_addr);
	printf(" icmp_seq=%d ttl=%d time=%.2Lf ms\n",  \
			ping->pstat.count + 1,
			ping->tstat.ttl, ping->tstat.intervale);
	return (1);
}

int	print_stat(t_ping *ping)
{
	printf("\n--- %s ping statistics ---\n", ping->host_entity->ai_canonname);
	printf("%d packets transmitted, %d received,"
			" %d%% packet loss, time %.0Lf ms\n",
			ping->pstat.send, ping->pstat.rcv,
			(int)(((double)(ping->pstat.send
						- ping->pstat.rcv) / ping->pstat.count) * 100),
			ping->tstat.all);
	printf("rtt min/avg/max/mdev = %.3Lf/%.3Lf/%.3Lf/%.3Lf ms\n",
			ping->tstat.min, ping->tstat.avg,
			ping->tstat.max, ping->tstat.mdev);
	return (1);
}

int	print_summary(t_ping *ping)
{
	printf("PING %s (%s) %ld(%d) bytes of data.\n",
			ping->host_entity->ai_canonname, ping->host_addr,
			sizeof(ping->packet), ping->pstat.size);
	return (1);
}
