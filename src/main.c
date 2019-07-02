/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:11:27 by ygarrot           #+#    #+#             */
/*   Updated: 2019/07/02 15:16:39 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_ping *g_ping;

int		usage(int ac, char **av)
{
	(void)av;
	if (ac < 2)
	{
		ft_printf("Please give me an address and (maybe) a port\n");
		return (1);
	}
	return (0);
}

void	ft_ping(t_ping *ping)
{
	set_packet(&ping->packet, ping);
	ping_send(&ping->packet, ping->socket, ping);
	intervale();
	ping_receive(ping->socket, ping);
	ping->tstat.intervale = intervale();
	if (!(ping->opt & QUIET))
		print_ping(ping);
	ping->pstat.count++;
	set_time_stat(ping);
}

int		ping_loop(t_ping *ping)
{
	int t = 1;

	if (setsockopt(ping->socket, IPPROTO_IP, IP_HDRINCL, 
				&t, sizeof(int)) != 0)
	{
		ft_printf("\nSetting socket options  TTL failed!\n");
		return (1);
	}
	gettimeofday(&ping->tstat.start, 0);
	while (1)
	{
		ft_printf("test");
		ft_ping(ping);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_ping	ping;

	g_ping = &ping;
	ft_bzero(&ping, sizeof(t_ping));
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
		return (EXIT_FAILURE);
	print_summary(&ping);
	ping_loop(&ping);
}
