/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setopt2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:45:19 by ygarrot           #+#    #+#             */
/*   Updated: 2019/07/14 14:06:36 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

/*
** -w
*/

void	set_deadline(t_ping *ping, char *value)
{
	ping->tstat.deadline = ft_atoi(value);
}

/*
** -W
*/

void	set_timeout(t_ping *ping, char *value)
{
	ping->tstat.timeout = ft_atoi(value);
}

void	display_help(t_ping *ping, char *value)
{
	char *usage;

	(void)ping;
	(void)value;
	usage = "Usage: ping [-cqditdw] [-c count]"
	" [-i interval] [-t ttl] [-w deadline] destination";
	printf("%s\n", usage);
}

void	func_tab(t_ping *ping)
{
	int		i;
	int		index;
	void	(*f[16])(t_ping *p, char *);

	f[ft_strlento(OPT_STR, 't')] = set_ttl;
	f[ft_strlento(OPT_STR, 's')] = set_packetsize;
	f[ft_strlento(OPT_STR, 'S')] = set_sndbuff;
	f[ft_strlento(OPT_STR, 'c')] = set_countmax;
	f[ft_strlento(OPT_STR, 'w')] = set_deadline;
	f[ft_strlento(OPT_STR, 'W')] = set_timeout;
	f[ft_strlento(OPT_STR, 'h')] = display_help;
	f[(int)ft_sqrt(INTERVALE)] = set_intervale;
	i = 1;
	index = 0;
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
