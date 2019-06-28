/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 12:03:22 by ygarrot           #+#    #+#             */
/*   Updated: 2018/06/09 12:18:02 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_replace(char *str, char *rep)
{
	int	i;

	i = -1;
	if (!str || !rep)
		return ;
	while (str[++i])
		if (str[i] == *rep)
		{
			if (!rep[1])
				ft_strcpy(&str[i], &str[i + 1]);
			else
				str[i] = rep[1];
		}
}
