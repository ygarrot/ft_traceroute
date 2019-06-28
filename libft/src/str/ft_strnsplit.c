/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:58:23 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/07 14:39:10 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int		countletters(char const *s, char c, int i2, int del)
{
	int cl;

	cl = 0;
	while ((s[i2 + cl] != c || !del) && s[i2 + cl])
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
		if (!(fresh[i] = ft_strnew(countletters(s, c, i2, words - i - 1))))
		{
			ft_free_dblechar_tab(fresh);
			return (NULL);
		}
		while ((s[i2] != c || !(words - i - 1)) && s[i2])
		{
			fresh[i][i3] = s[i2];
			i2++;
			i3++;
		}
	}
	return (fresh);
}

char			**ft_strnsplit(char const *s, char c, int n)
{
	char	**fresh;
	int		words;

	if (!(n && s && c))
		return (NULL);
	words = ft_ismin(n, countwords(s, c));
	if (!(fresh = (char**)ft_memalloc((words + 1) * sizeof(char*))))
		return (NULL);
	return (cpy(s, c, fresh, words));
}
