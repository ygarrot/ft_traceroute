/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlento_rev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:05:10 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/25 10:12:22 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlento_rev(char *str, int size, char *lim)
{
	int	i;
	int	n;

	if (!str || !lim || !*lim)
		return (0);
	i = 0;
	n = ft_strlen(lim);
	while (i < size && ft_strncmp(&str[size - i], lim, n))
		i++;
	if (i == size && ft_strncmp(str, lim, n))
		return (-1);
	return (size - i);
}
