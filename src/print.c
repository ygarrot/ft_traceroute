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
	printf("traceroute to %s (%s), %d hops max, %ld bytes packets\n",
			ping->host_entity->ai_canonname, ping->host_addr,
			ping->env.max_ttl,
			sizeof(ping->packet));
	return (1);
}

int	print_foreach(t_ping *ping)
{
	static int	current_ttl = 1;
	int		i;


	if (!ping->route[current_ttl].addr || ping->route[current_ttl].done != 3)
		return (1);
	if (current_ttl == ping->last_ttl)
		ping->done = 1;
	i = -1;
	printf("%3d %s", current_ttl, ping->route[current_ttl].addr);
	ft_strdel(&ping->route[current_ttl].addr);
	while (++i < ping->env.max_tries)
		printf(" %.3fms", timeval_to_double(ping->route[current_ttl].tries[i]));
	printf("\n");
	++current_ttl;
	return(print_foreach(ping));
}
