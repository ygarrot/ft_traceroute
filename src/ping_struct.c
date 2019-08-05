/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:10:14 by ygarrot           #+#    #+#             */
/*   Updated: 2019/08/05 10:47:04 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

void	free_routes(t_route *route, int ttl)
{
	while (--ttl > -1)
	{
		ft_memdel((void**)&route[ttl].tries);
		free(route[ttl].done);
		ft_strdel(&route[ttl].addr);
	}
	free(route);
}

void	set_routes(t_ping *ping, int i)
{
	if (i >= ping->env.max_ttl)
		return ;
	if (!(ping->route[i].tries = (struct timeval*)ft_memalloc(
		sizeof(struct timeval) * ping->env.max_tries)))
	{
		free_routes(ping->route, ping->env.max_ttl);
		ft_exit("malloc failed", EXIT_FAILURE);
	}
	if (!(ping->route[i].done = (bool*)ft_memalloc(
					sizeof(bool) * ping->env.max_tries)))
		ft_exit("malloc failed", EXIT_FAILURE);
	set_routes(ping, ++i);
}

void	ping_ctor(t_ping *ping)
{
	ping->env.max_ttl = MAX_TTL;
	ping->env.max_tries = MAX_TRIES;
	ping->env.timeout = DEFAULT_TIMEOUT;
	ping->env.ttl = 1;
	ping->env.tries = -1;
	ping->last_ttl = -1;
	func_tab(ping);
	ping->env.first_ttl = ping->env.ttl;
	if (!(ping->route = (struct s_route*)ft_memalloc(
				sizeof(struct s_route) * ping->env.max_ttl)))
		ft_exit("malloc failed", EXIT_FAILURE);
	set_routes(ping, 0);
}
