/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dlbint_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 12:05:02 by ygarrot           #+#    #+#             */
/*   Updated: 2018/03/11 12:47:27 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_dblint_tab(int **tab, int size)
{
	int		temp;

	temp = 0;
	if (!tab)
		return ;
	while (temp < size)
		ft_memdel((void**)&tab[temp++]);
	ft_memdel((void**)&tab);
}
