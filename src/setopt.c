/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setopt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:27:10 by ygarrot           #+#    #+#             */
/*   Updated: 2019/07/14 14:06:36 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

/*
** -f first ttl
*/

void	set_ttl(t_ping *ping, char *value)
{
	ping->env.ttl = ft_atoi(value);
}

/*
** -m max ttl
*/

void	set_max_ttl(t_ping *ping, char *value)
{
	ping->env.max_ttl = ft_atoi(value);
}

/*
** -q tries number
*/

void	set_max_tries(t_ping *ping, char *value)
{
	ping->env.max_tries= ft_atoi(value);
}

/*
** -t tos 
*/

void	set_tos(t_ping *ping, char *value)
{
	ping->env.tos = ft_atoi(value);
}

/*
** -w wait
*/

void	set_timeout(t_ping *ping, char *value)
{
	ping->env.timeout = atof(value);
}
