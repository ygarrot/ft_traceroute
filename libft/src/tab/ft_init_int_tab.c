/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 11:48:37 by ygarrot           #+#    #+#             */
/*   Updated: 2018/01/01 12:32:04 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_init_int_tab(int size)
{
	int		*emptytab;

	if (!(emptytab = (int*)malloc(size * sizeof(int))))
		return (NULL);
	while (size--)
		emptytab[size] = 0;
	return (emptytab);
}
