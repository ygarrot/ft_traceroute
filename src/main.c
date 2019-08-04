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
	ft_printf("traceroute: missing host operand\n\
Try 'traceroute --help' or 'traceroute --usage' for more information. \n");
	return (1);
}

void	ft_ping(t_ping *ping)
{
	if (++ping->env.tries >= ping->env.max_tries)
	{
		ping->env.tries = 0;
		++ping->env.ttl;
       	}
	if (ping->env.ttl >= ping->env.max_ttl)
		return ;
	set_packet(ping);
	ping_send(ping->socket, ping);
	if (gettimeofday(&ping->route[ping->env.ttl].tries[ping->env.tries], 0) == ERROR_CODE)
		printf("gettime of day error\n");
	ft_ping(ping);
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
	ping.env.ttl = 1;
	ping.env.tries = -1;
	if ((ping.socket = check_addr(&ping)) == ERROR_CODE)
		ft_exit("check addr", EXIT_FAILURE);
	print_summary(&ping);
	ft_ping(&ping);
	ping_receive(ping.socket, &ping, 0);
	free_routes(ping.route, ping.env.max_ttl);
}
