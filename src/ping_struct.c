/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:10:14 by ygarrot           #+#    #+#             */
/*   Updated: 2019/07/14 14:06:36 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

void	free_routes(t_route *route, int ttl)
{
	while (--ttl)
	{
		free(route[ttl].tries);
		/* free(route[ttl].addr); */
	}
	free(route);
}

void set_routes(t_ping *ping, int i)
{
	if (i >= ping->env.max_ttl)
		return ;
	if (!(ping->route[i].tries = (struct timeval*)ft_memalloc(sizeof(struct timeval) * ping->env.max_tries)))
	{
		free_routes(ping->route, ping->env.max_ttl);
		ft_exit("malloc failed", EXIT_FAILURE);
	}
	set_routes(ping, ++i);
}

void	ping_ctor(t_ping *ping)
{
	ft_bzero(&ping->packet, sizeof(ping->packet));

	ping->env.max_ttl = MAX_TTL; 
	ping->env.max_tries = MAX_TRIES;
	ping->env.timeout = DEFAULT_TIMEOUT;
	ping->last_ttl = -1;
	if (!(ping->route = (struct route*)ft_memalloc(sizeof(struct route) * ping->env.max_ttl)))
		ft_exit("malloc failed", EXIT_FAILURE);
	set_routes(ping, 0);
	func_tab(ping);
}
