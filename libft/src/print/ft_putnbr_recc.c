/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_recc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 15:47:54 by ygarrot           #+#    #+#             */
/*   Updated: 2018/01/18 13:52:40 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_putnbr_recc(int value)
{
	unsigned int	temp;
	int				mod;
	char			c;

	mod = 1;
	value < 0 ? write(1, "-", 1) : 0;
	temp = (value > 0) ? value : -value;
	value = (value == INT_MIN) ? value - 1 : value;
	while ((value /= 10) > 0)
		mod *= 10;
	c = (temp / mod) + '0';
	write(1, &c, 1);
	if (mod < 10)
		return ;
	ft_putnbr_recc(temp % mod);
}
