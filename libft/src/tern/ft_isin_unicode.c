/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isin_unicode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:19:35 by tcharrie          #+#    #+#             */
/*   Updated: 2018/06/19 13:32:43 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isin_unicode(char *str, char *look)
{
	int	i;
	int	j;

	if (!str || !look || !*str)
		return (0);
	i = 0;
	j = ft_lenchar_r(str, 0);
	if (j < 0)
		return (0);
	while (look[i])
	{
		if (!ft_strncmp(str, &look[i], (size_t)j))
			return (1);
		i += ft_lenchar_r(look, i);
	}
	return (0);
}
