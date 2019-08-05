/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setopt2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:45:19 by ygarrot           #+#    #+#             */
/*   Updated: 2019/08/05 10:53:20 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

void	display_help(t_ping *ping, char *value)
{
	char *usage;

	(void)ping;
	(void)value;
	usage = "Usage: traceroute [OPTION...] HOST\n"
		"Print the route packets trace to network host.\n"
		"\n"
		"-f,     set initial hop distance, i.e., time-to-live\n"
		"-m,     set maximal hop count (default: 64)\n"
		"-p,     use destination PORT port (default: 33434)\n"
		"-q,     send NUM probe packets per hop (default: 3)\n"
		"resolve hostnames\n"
		"-t,     set type of service (TOS) to NUM\n"
		"-w,     wait NUM seconds for response (default: 3)\n"
		"-?,     give this help list\n"
		"give a short usage message\n"
		;
	printf("%s\n", usage);
}

void	func_tab(t_ping *ping)
{
	int		i;
	int		index;
	void	(*f[16])(t_ping *p, char *);

	i = 1;
	index = 0;
	f[ft_strlento(OPT_STR, 'f')] = set_ttl;
	f[ft_strlento(OPT_STR, 'm')] = set_max_ttl;
	f[ft_strlento(OPT_STR, 'q')] = set_max_tries;
	f[ft_strlento(OPT_STR, 't')] = set_tos;
	f[ft_strlento(OPT_STR, 'w')] = set_timeout;
	f[ft_strlento(OPT_STR, '?')] = display_help;
	while (i < (1 << 30))
	{
		if (ping->opt & i && f[index] && ping->opt_tab[index])
		{
			f[index](ping, ping->opt_tab[index]);
		}
		index++;
		i <<= 1;
	}
}
