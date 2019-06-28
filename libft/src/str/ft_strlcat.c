/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:50:19 by ygarrot           #+#    #+#             */
/*   Updated: 2017/11/14 21:06:47 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	res(size_t temp, size_t size)
{
	if (size > temp)
		return (temp);
	else
		return (size);
}

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	i2;
	size_t	temp;

	temp = 0;
	i2 = 0;
	i = 0;
	i = ft_strlen(dest);
	temp = i;
	if (size == 0)
		return (ft_strlen((char*)src));
	while (i < size - 1 && src[i2])
	{
		dest[i] = src[i2];
		i++;
		i2++;
	}
	dest[i] = '\0';
	return (res(temp, size) + ft_strlen((char*)src));
}
