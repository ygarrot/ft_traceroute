/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblstr_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:02:04 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/11 14:25:41 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dblstr_add(char ***t, char *str)
{
	int		i;
	char	**tmp;

	if (!t)
		return (-1);
	if (!str)
		return (0);
	i = 0;
	while (t[0] && t[0][i])
		i++;
	if (!(tmp = (char**)malloc(sizeof(char*) * (i + 2))))
		return (-1);
	i = -1;
	while (t[0] && t[0][++i])
		tmp[i] = t[0][i];
	if (i < 0)
		i = 0;
	tmp[i] = str;
	tmp[i + 1] = 0;
	free(*t);
	*t = tmp;
	return (0);
}
