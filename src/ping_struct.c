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

void	free_routes(t_route *route, size_t ttl)
{
	while (ttl--)
		free(route[ttl].tries);
	free(route);
}

void	ping_ctor(t_ping *ping)
{
	int i;

	i = -1;
	ft_bzero(&ping->packet, sizeof(ping->packet));

	ping->env.max_ttl = MAX_TTL; 
	ping->env.max_tries = MAX_TRIES;
	if (!(ping->route = (struct route*)malloc(sizeof(struct route) * ping->env.max_ttl)))
		ft_exit("malloc failed", EXIT_FAILURE);
	while (++i < ping->env.max_ttl)
	{
		if (!(ping->route[i].tries = (struct timeval*)malloc(sizeof(struct timeval) * ping->env.max_tries)))
		{
			free_routes(ping->route, ping->env.max_ttl);
			ft_exit("malloc failed", EXIT_FAILURE);
		}
	}
	func_tab(ping);
}
