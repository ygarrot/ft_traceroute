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

double	res(t_timeval last_time, t_timeval current_time)
{
	double intervale;

	intervale = (double)(current_time.tv_sec - last_time.tv_sec) * 1000.0;
	intervale += (double)(current_time.tv_usec - last_time.tv_usec)
		/ 1000.0;
	return (intervale);
}

int	print_foreach(t_ping *ping)
{
	static int	current_ttl = 1;
	static int	current_try = 0;

	if (ping->env.ttl < current_ttl
			|| current_ttl >= ping->env.max_ttl
			|| (ping->env.ttl == current_ttl
		       	&& ping->env.tries <= current_try)
	   )
	{
		return (1);
	}
	if ((!ping->route[current_ttl].addr
	&& !ping->route[current_ttl].done[current_try]) && ping->timedout)
		return (1);
	if (current_try == 0)
		printf("%3d   %s", current_ttl, ping->timedout ? ping->route[current_ttl].addr : "");
	if (ping->route[current_ttl].done[current_try])
		printf(" %.3fms", timeval_to_double(ping->route[current_ttl].tries[current_try]));
	else
	{
		printf(" *");
	}
	fflush(0);
	++current_try;
	if (current_try == ping->env.max_tries)
	{
		ping->done = current_ttl == ping->last_ttl;
		printf("\n");
		++current_ttl;
		current_try = 0;
	}
	/* return (1); */
	return (print_foreach(ping));
}
