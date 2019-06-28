/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:54:57 by ygarrot           #+#    #+#             */
/*   Updated: 2017/11/11 15:54:43 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static int		neg(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	return (n);
}

static void		exception(int fd)
{
	int o;

	o = 100000000;
	ft_putchar_fd('2', fd);
	while (o >= 10)
	{
		ft_putchar_fd(((214748364 % o) / (o / 10)) + '0', fd);
		o = o / 10;
	}
	ft_putchar_fd('8', fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	int i;
	int o;

	n = neg(n, fd);
	i = n;
	o = 1;
	while (i >= 10)
	{
		i = i / 10;
		o = o * 10;
	}
	if (n == (-2147483648))
		exception(fd);
	else
	{
		ft_putchar_fd(n / o + '0', fd);
		while (o >= 10)
		{
			ft_putchar_fd(((n % o) / (o / 10)) + '0', fd);
			o = o / 10;
		}
	}
}
