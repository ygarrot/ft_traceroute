/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dbl_inttab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 18:36:48 by ygarrot           #+#    #+#             */
/*   Updated: 2018/01/18 13:53:07 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_dbl_inttab(int **tab, size_t size1, size_t size2)
{
	size_t		row;
	size_t		length;

	row = 0;
	if (!tab)
		return ;
	length = 0;
	ft_printf("     ");
	while (length < size2)
		ft_printf("%02d|", (int)length++);
	ft_printf("\n");
	while (row < size1)
	{
		length = 0;
		ft_printf("[%02d] ", (int)row);
		while (length < size2)
		{
			ft_printf("%02d ", tab[row][length]);
			length++;
		}
		ft_printf("\n");
		row++;
	}
}
