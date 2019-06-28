/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:16:52 by ygarrot           #+#    #+#             */
/*   Updated: 2019/06/24 14:02:49 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	if (!n)
		return (NULL);
	while (i < n && ((unsigned char*)s)[i] != (unsigned char)c)
		i++;
	return ( i == n ? NULL : &((unsigned char*)s)[i]);
}
