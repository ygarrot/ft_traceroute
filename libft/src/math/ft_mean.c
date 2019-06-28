/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mean.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:08:27 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/29 16:22:31 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_mean(double *array, int len)
{
	int			i;
	long double	sum;

	i = len;
	sum = 0.0;
	while (i)
	{
		sum += *array;
		array++;
		i--;
	}
	return ((double)(sum / len));
}
