/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 12:14:51 by tcharrie          #+#    #+#             */
/*   Updated: 2018/06/13 13:09:02 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strprefix(char *pref, char *str)
{
	int	i;

	if (!pref || !str)
		return (0);
	i = 0;
	while (pref[i] && ft_abs(pref[i]) == ft_abs(str[i]))
		i++;
	if (pref[i])
		return (0);
	return (i);
}
