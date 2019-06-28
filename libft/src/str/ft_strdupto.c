/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupto.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 15:18:12 by tcharrie          #+#    #+#             */
/*   Updated: 2018/02/03 15:21:04 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupto(char *old, char to)
{
	char	*str;
	int		i;
	int		j;

	if (!old)
		return (NULL);
	i = ft_strlento(old, to);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	j = 0;
	while (j < i)
	{
		str[j] = old[j];
		j++;
	}
	str[j] = 0;
	return (str);
}
