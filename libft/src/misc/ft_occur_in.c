/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_occur_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:50:48 by ygarrot           #+#    #+#             */
/*   Updated: 2018/01/19 13:53:18 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_occur_in(char *str, char c)
{
	int		occurence;
	size_t	i;

	occurence = 0;
	i = 0;
	while (str && str[i])
		if (str[i++] == c)
			occurence++;
	return (occurence);
}
