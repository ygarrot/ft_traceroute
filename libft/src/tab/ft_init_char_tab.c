/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_char_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 11:51:23 by ygarrot           #+#    #+#             */
/*   Updated: 2018/01/18 13:25:52 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_init_double_tab(int size, int size2)
{
	char		**emptytab;
	int			index;

	index = 0;
	if (!(emptytab = (char**)malloc((size + 1) * sizeof(char*))))
		return (NULL);
	while (index < size)
	{
		if (!(emptytab[index] = ft_strnew(size2)))
		{
			ft_free_dblechar_tab(emptytab);
			return (NULL);
		}
		index++;
	}
	emptytab[size] = NULL;
	return (emptytab);
}
