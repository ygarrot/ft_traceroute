/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initdbl_int_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 17:42:35 by ygarrot           #+#    #+#             */
/*   Updated: 2018/01/18 13:50:36 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_initdbl_int_tab(size_t size1, size_t size2)
{
	int			**tab;
	size_t		row;
	size_t		length;

	row = 0;
	if (!(tab = (int**)ft_memalloc(sizeof(int**) * size1)))
		return (NULL);
	while (row < size1)
	{
		length = 0;
		if (!(tab[row] = (int*)ft_memalloc(sizeof(int) * size2)))
		{
			ft_free_dblint_tab(tab, row);
			return (NULL);
		}
		row++;
	}
	return (tab);
}
