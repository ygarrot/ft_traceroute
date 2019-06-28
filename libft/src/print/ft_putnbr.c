/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:41:31 by ygarrot           #+#    #+#             */
/*   Updated: 2017/11/11 15:53:36 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void		ft_putchar(char c)
{
	write(1, &c, 1);
}

static int		neg(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	return (n);
}

static void		exception(void)
{
	int o;

	o = 100000000;
	ft_putchar('2');
	while (o >= 10)
	{
		ft_putchar(((214748364 % o) / (o / 10)) + '0');
		o = o / 10;
	}
	ft_putchar('8');
}

void			ft_putnbr(int n)
{
	int i;
	int o;

	n = neg(n);
	i = n;
	o = 1;
	while (i >= 10)
	{
		i = i / 10;
		o = o * 10;
	}
	if (n == (-2147483648))
		exception();
	else
	{
		ft_putchar(n / o + '0');
		while (o >= 10)
		{
			ft_putchar(((n % o) / (o / 10)) + '0');
			o = o / 10;
		}
	}
}
