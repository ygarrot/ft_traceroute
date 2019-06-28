/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 11:07:21 by ygarrot           #+#    #+#             */
/*   Updated: 2018/12/31 16:36:01 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	reset_int_tab(int *i, int row)
{
	if (!i)
		return ;
	while (row--)
		i[row] = 0;
}

int		ft_printf(const char *str, ...)
{
	va_list		printlist;
	t_arg		list;
	int			i[4];

	list.length = 0;
	reset_int_tab(i, 2);
	va_start(printlist, str);
	i[2] = -1;
	if (str[0] == '%' && !str[1])
		return (0);
	while (str[++i[2]])
		if ((str[i[2]] == '{' || str[i[2]] == '%') &&
				putf(printlist, &list, &str[i[2]], i) && i[0] > 0)
			i[2] = i[0];
		else if (++i[1])
			write(1, &str[i[2]], 1);
	va_end(printlist);
	return (i[1]);
}

int		*putf(va_list va, t_arg *list, const char *str, int *i)
{
	i[0] = 0;
	if (!initlist(list))
		return (0);
	if (str[0] == '%')
	{
		i[0] = parse_arg(str, list);
		(list->wild & 1) ? list->champ = va_arg(va, unsigned int) : 0;
		(list->wild & 2) ? list->pre = va_arg(va, unsigned int) : 0;
		if (i[0])
			print1(chooseconv(va, list), list);
	}
	else
	{
		i[0] = parse_colors((char*)str, list);
		if (i[0])
			colorise(list);
		else
			i[0] = -1;
	}
	if (i[0] >= 0)
	{
		i[1] += list->length;
		i[0] += i[2];
	}
	return (i);
}
