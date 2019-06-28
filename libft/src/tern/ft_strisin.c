/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 12:12:57 by ygarrot           #+#    #+#             */
/*   Updated: 2018/01/09 10:42:19 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisin(char *tofind, char *str)
{
	size_t		i;

	i = 0;
	if (!str || !tofind)
		return (0);
	while (str[i] && tofind[i] && str[i] == tofind[i])
		i++;
	return ((!str[i--] && i && str[i] == tofind[i]) ? 1 : 0);
}
