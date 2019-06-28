/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_implode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 14:25:29 by ygarrot           #+#    #+#             */
/*   Updated: 2018/05/29 11:31:39 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*concat(char *glue, char const *s1, char const *s2, char *fresh)
{
	int		i;
	int		i2;
	int		i3;

	i2 = -1;
	i = -1;
	i3 = -1;
	while (s1[++i])
		fresh[i] = s1[i];
	while (glue[++i3])
		fresh[i++] = glue[i3];
	while (s2[++i2])
		fresh[i++] = s2[i2];
	return (fresh);
}

char			*ft_implode(char *glue, char const *s1, char const *s2)
{
	int		i;
	int		i2;
	char	*fresh;

	if (!(glue && s1 && s2))
		return (!glue ? ft_strjoin(s1, s2) : NULL);
	i = ft_strlen(s1) + ft_strlen(glue);
	i2 = ft_strlen(s2);
	if (!(fresh = ft_strnew((i + i2 + 1))))
		return (NULL);
	return (concat(glue, s1, s2, fresh));
}
