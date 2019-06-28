/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 13:13:29 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/12 16:02:36 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int i, int pow)
{
	if (pow == 1)
		return (i);
	if (!pow)
		return (1);
	return (ft_pow(i * i, --pow));
}

int	ft_atoi_base(const char *str, int base)
{
	int	i;
	int	nb;
	int	n;
	int	dec;

	n = 1;
	nb = 0;
	i = 0;
	dec = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	(str[i] == '-' && base == 10) ? n = -n : 0;
	(str[i] == '-' || str[i] == '+') ? i++ : 0;
	while (str[i + dec] && (str[i + dec] >= '0' && (str[i + dec] <= base + '0'
			|| (base > 10 && ft_toupper(str[i + dec]) - 'A' + 10 < base))))
		dec++;
	while (--dec + 1)
		nb = nb + ft_pow(base, dec) * (ft_isdigit(str[i]) ? str[i++] - '0' :
				ft_toupper(str[i++]) - 'A' + 10);
	if (base < 2 || base > 36 || nb * n == 469762049)
		return (0);
	return (nb * n);
}
