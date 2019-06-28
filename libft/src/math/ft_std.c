/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:32:43 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/29 16:23:35 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_std(double *array, int len)
{
	double	sum;
	double	std;
	int		mean;
	int		i;

	i = len;
	sum = 0.0;
	mean = ft_mean(array, len);
	while (i)
	{
		sum += ft_power(array[i] - mean, 2);
	}
	std = (1 / len) * sum;
	std = ft_sqrt(std);
	return (std);
}
