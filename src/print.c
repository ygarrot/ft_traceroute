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

int	print_summary(t_ping *ping)
{
	printf("traceroute to %s (%s), %d max hope %ld bytes packets\n",
			ping->host_entity->ai_canonname, ping->host_addr,
			ping->env.max_ttl,
			sizeof(ping->packet));
	return (1);
}

int	print_foreach(t_ping *ping, int *ttls)
{
	static int current_ttl = 0;
	int		i;

		
	i = -1;
	while (ttls[current_ttl] == 3)
	{
		printf("%d %s", current_ttl, ping->route[current_ttl].addr);
		while (++i < ping->env.max_tries)
		{
			;
			/* printf("%dms", ping->route[current_ttl].tries[i]); */
		}
	}
	return (1);
}
