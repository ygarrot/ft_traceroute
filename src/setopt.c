/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setopt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:27:10 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/29 16:07:40 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

/*
** -t
*/

void	set_ttl(t_ping *ping, char *value)
{
	if (ft_atoi(value) > 255)
		return ;
	ping->tstat.ttl = ft_atoi(value);
}

/*
** -S
*/

void	set_sndbuff(t_ping *ping, char *value)
{
	ping->pstat.sndbuff = ft_atoi(value);
}

/*
** -s
*/

void	set_packetsize(t_ping *ping, char *value)
{
	ping->pstat.size = ft_atoi(value);
}

/*
** -c
*/

void	set_countmax(t_ping *ping, char *value)
{
	if (ft_atoi(value) <= 0)
	{
		ft_putendl_fd(PING_BAD_COUNT, STDERR_FILENO);
		return ;
	}
	ping->pstat.count_max = ft_atoi(value);
}

/*
** -i
*/

void	set_intervale(t_ping *ping, char *value)
{
	ping->tstat.delay = atof(value);
}
