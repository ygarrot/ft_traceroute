/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:05:03 by ygarrot           #+#    #+#             */
/*   Updated: 2018/01/18 13:50:56 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_search_char(char *str, char c, int end)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	if (end)
		while (str[end] && str[end] != c)
			end--;
	else
		while (str[end] && str[end] != c)
			end++;
	if (str[end])
		return (end);
	return (-1);
}
