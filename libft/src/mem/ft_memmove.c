/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:48:38 by ygarrot           #+#    #+#             */
/*   Updated: 2017/11/14 14:38:12 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int		ft_is_overlap(void *dst, const void *src, size_t len)
{
	while (len--)
	{
		if (src == dst)
			return (1);
		src++;
	}
	return (0);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	if (ft_is_overlap(dst, src, len))
	{
		dst = dst + len;
		src = src + len;
		while (len--)
		{
			src--;
			dst--;
			*(unsigned char*)dst = *(unsigned char*)src;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
