/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:58:42 by ygarrot           #+#    #+#             */
/*   Updated: 2017/11/12 17:43:17 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		*mem(int n, int i, char *fresh)
{
	if (n < 0)
		i++;
	if ((fresh = (char*)malloc((i + 1) * sizeof(char))) == NULL)
		return (0);
	if (n < 0)
		fresh[0] = '-';
	return (fresh);
}

static int		negatif(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

static char		*cpy(int i, int i2, int n)
{
	int		i3;
	char	*fresh;

	i3 = 0;
	fresh = NULL;
	if ((fresh = mem(n, i, fresh)) == 0)
		return (0);
	if (n < 0)
	{
		i3 = 1;
		i++;
	}
	while (i3 < i)
	{
		fresh[i3] = ((n * negatif(n)) / i2 % 10) + '0';
		i2 = i2 / 10;
		i3++;
	}
	fresh[i3] = '\0';
	return (fresh);
}

static char		*exception(void)
{
	int		i2;
	int		i3;
	char	*fresh;

	i3 = 1;
	fresh = NULL;
	if ((fresh = (char*)malloc(12 * sizeof(char))) == NULL)
		return (0);
	i2 = 100000000;
	fresh[0] = '-';
	while (i3 < 10)
	{
		fresh[i3] = ((214748364 / i2 % 10) + '0');
		i2 = i2 / 10;
		i3++;
	}
	fresh[10] = '8';
	fresh[11] = '\0';
	return (fresh);
}

char			*ft_itoa(int n)
{
	int i;
	int i2;
	int nb;

	nb = n;
	i = 1;
	i2 = 1;
	if (n == -2147483648)
		return (exception());
	while (nb * negatif(n) >= 10)
	{
		nb = nb / 10;
		i2 = i2 * 10;
		i++;
	}
	return (cpy(i, i2, n));
}
