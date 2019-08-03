/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:11:27 by ygarrot           #+#    #+#             */
/*   Updated: 2019/08/02 10:48:55 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

t_ping *g_ping;

int		usage(int ac, char **av)
{
	(void)av;
	if (ac >= 2)
		return (0);
	ft_printf("Please give me an address and (maybe) a port\n");
	return (1);
}

void	ft_ping(t_ping *ping)
{
	ping->env.ttl = 0;
	while (++ping->env.ttl < ping->env.max_ttl)
	{
		ping->env.tries = -1;
		while (++ping->env.tries < ping->env.max_tries)
		{
			gettimeofday(&ping->route[ping->env.ttl].tries[ping->env.tries], 0);
			set_packet(ping);
			ping_send(ping->socket, ping);
		}
	}
	ping_receive(ping->socket, ping);
}

int		main(int ac, char **av)
{
	t_ping	ping = { 0 };

	g_ping = &ping;
	if (usage(ac, av))
		return (1);
	ping.opt = ft_getoptvalue(ac, av, OPT_STR, ping.opt_tab);
	if (ping.opt & HELP)
	{
		display_help(0, 0);
		return (1);
	}
	ping_ctor(&ping);
	ping.host_name = av[1];
	if ((ping.socket = check_addr(&ping)) == ERROR_CODE)
		ft_exit("check addr", EXIT_FAILURE);
	print_summary(&ping);
	ft_ping(&ping);
}
