/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 14:49:30 by ygarrot           #+#    #+#             */
/*   Updated: 2019/07/14 14:06:43 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_traceroute.h"

/*
** struct timeval {
**     time_t      tv_sec;      seconds
**     suseconds_t tv_usec;     microseconds
** };
**
** struct timezone {
**     int tz_minuteswest;      minutes west of Greenwich
**     int tz_dsttime;          type of DST correction
** };
** The tz_dsttime field has never been used under Linux.
** Thus, the following is purely of historic interest.
*/

double	timeval_to_double(t_timeval current_time)
{
	double intervale;

	intervale = (double)(current_time.tv_sec) * 1000.0;
	intervale += (double)(current_time.tv_usec) / 1000.0;
	return (-intervale);
}
