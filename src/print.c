/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:56:47 by ygarrot           #+#    #+#             */
/*   Updated: 2019/08/05 11:02:21 by ygarrot          ###   ########.fr       */
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

int	check_ttl(t_ping *ping, int current_ttl, int current_try)
{
	return ((ping->env.ttl < current_ttl
			|| current_ttl >= ping->env.max_ttl
			|| (ping->env.ttl == current_ttl && ping->env.tries <= current_try))
			|| ((!ping->route[current_ttl].addr
			&& !ping->route[current_ttl].done[current_try]) && ping->timedout));
}

int	print_foreach(t_ping *ping)
{
	int			current_ttl;
	static int	current_try = 0;

	current_ttl = ping->env.first_ttl;
	if (check_ttl(ping, current_ttl, current_try))
		return (1);
	if (current_try == 0)
		printf("%3d   %s", current_ttl,
				ping->timedout ? ping->route[current_ttl].addr : "");
	if (ping->route[current_ttl].done[current_try])
		printf("  %.3fms",
			timeval_to_double(ping->route[current_ttl].tries[current_try]));
	else
		printf(" *");
	if (++current_try >= ping->env.max_tries)
	{
		ping->done = current_ttl == ping->last_ttl
			|| current_ttl == 255;
		printf("\n");
		++ping->env.first_ttl;
		current_try = 0;
	}
	return (print_foreach(ping));
}
