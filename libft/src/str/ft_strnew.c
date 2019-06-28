/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:44:33 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/07 13:49:21 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	size_t	i;
	void	*buf;

	buf = NULL;
	i = 0;
	if (size > 9223372036854775807)
		return (NULL);
	if (!(buf = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (i < size + 1)
	{
		((unsigned char*)buf)[i] = '\0';
		i++;
	}
	return (buf);
}
