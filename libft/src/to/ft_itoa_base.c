/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:21:23 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/11 13:38:23 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoabase(int nbr, int base)
{
	long		value;
	long		result;
	long		neg;
	int			i;
	char		*str;

	value = nbr;
	neg = (base == 10 && (value < 0));
	i = neg;
	value = (value > 0) ? value : -value;
	result = value;
	while (result /= base)
		i++;
	if (!(str = (char*)malloc((i + 2) * sizeof(char))))
		return (NULL);
	str[i + 1] = '\0';
	while (value > 0)
	{
		str[i--] = ((value % base) < 10) ?
			(value % base) + '0' : (value % base) - 10 + 'a';
		value /= base;
	}
	str[0] = neg ? '-' : str[0];
	return (str);
}
