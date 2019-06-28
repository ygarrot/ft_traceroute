/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizeof_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 18:12:05 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/11 14:35:33 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_sizeof_tab(char **tab)
{
	size_t i;
	size_t i2;

	i = 0;
	i2 = -1;
	if (!tab)
		return (0);
	while (tab[++i2])
		i += ft_strlen(tab[i2]) + 1;
	return (i + ((i2 + 1) * sizeof(char**)));
}
