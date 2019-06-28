/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:21:06 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/13 12:12:43 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		countwords(char const *s, char c)
{
	int i;
	int i2;

	i = 0;
	i2 = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			i2++;
		while (s[i] != c && s[i])
			i++;
	}
	return (i2);
}

static int		countletters(char const *s, char c, int i2)
{
	int cl;

	cl = 0;
	while (s[i2 + cl] != c && s[i2 + cl])
		cl++;
	return (cl);
}

static char		**cpy(char const *s, char c, char **fresh, int words)
{
	int		i;
	int		i3;
	int		i2;

	i = -1;
	i2 = 0;
	while (++i < words)
	{
		i3 = 0;
		while (s[i2] == c && s[i2])
			i2++;
		if (!(fresh[i] = ft_strnew(countletters(s, c, i2))))
		{
			ft_free_dblechar_tab(fresh);
			return (NULL);
		}
		while (s[i2] != c && s[i2])
		{
			fresh[i][i3] = s[i2];
			i2++;
			i3++;
		}
	}
	return (fresh);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**fresh;
	int		words;

	if (!(s && c))
		return (NULL);
	words = countwords(s, c);
	if (!(fresh = (char**)ft_memalloc((words + 1) * sizeof(char*))))
		return (NULL);
	return (cpy(s, c, fresh, words));
}
