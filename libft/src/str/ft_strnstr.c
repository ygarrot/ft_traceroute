/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:08:30 by ygarrot           #+#    #+#             */
/*   Updated: 2017/11/12 17:41:17 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	if (!s2[0])
		return ((char*)(&s1[0]));
	while (s1[i] && i < len)
	{
		i2 = 0;
		while (s1[i + i2] == s2[i2] && (i + i2) < len)
		{
			i2++;
			if (!s2[i2])
				return ((char*)(&s1[i]));
		}
		i++;
	}
	return (0);
}
