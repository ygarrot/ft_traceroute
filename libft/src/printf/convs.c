/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 20:54:47 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/07 16:01:59 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*convc(int nb)
{
	char *str;

	if (!(str = (char*)malloc(2 * sizeof(char))))
		return (NULL);
	str[0] = (char)nb;
	str[1] = '\0';
	return (str);
}

int				bin_count(wchar_t v)
{
	int		size;

	size = 0;
	while (v /= 2)
		size++;
	if (size < 8)
		size = 0;
	else if (size < 12)
		size = 1;
	else if (size < 17)
		size = 2;
	else
		size = 3;
	return (size);
}

char			*convwchar(wchar_t v)
{
	int				size;
	char			*str;
	int				temp2;

	temp2 = 0;
	size = bin_count(v);
	if (!(str = (char*)malloc((unsigned long)(++size) * sizeof(char))))
		return (NULL);
	str[size--] = '\0';
	if (size > 0)
	{
		str[temp2++] = (char)(((v >> size * 6) | 192)
		+ (size > 1 ? size * 16 : 0));
		while (size-- > 0)
			str[temp2++] = (char)((v >> size * 6 & 0x3f) | 0x80);
	}
	else
		str[temp2] = (char)v;
	return (str);
}

char			*convwstr(wchar_t *str)
{
	size_t	i;
	char	*result;
	char	*temp;

	result = NULL;
	temp = NULL;
	if (str)
		result = (char*)ft_memalloc(1);
	i = 0;
	while (str && str[i])
	{
		temp = convwchar(str[i++]);
		result = ft_strjoin(result, temp);
	}
	return (result);
}
