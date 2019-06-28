/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecolor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 17:53:43 by ygarrot           #+#    #+#             */
/*   Updated: 2018/01/27 09:56:03 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		parse_colors(char *str, t_arg *tempm)
{
	char	**att;
	char	**colors;
	int		temp;
	int		index;

	att = (char *[7]) {"reset", "bold", "low", "italic", "blink", "reverse"
		, "conc"};
	colors = (char *[8]){"black", "red", "green", "yellow", "blue", "magenta"
		, "cyan", "white"};
	index = 1;
	temp = ft_strisin_tab(&str[index], att, 7);
	tempm->att = (temp >= 0) ? temp : -1;
	index += (temp >= 0) ? ft_strlen(att[temp]) : 0;
	temp = ft_strisin_tab(&str[index], colors, 8);
	tempm->fg = (temp >= 0) ? temp : -1;
	index += (temp >= 0) ? ft_strlen(colors[temp]) : 0;
	temp = ft_strisin_tab(&str[index], colors, 8);
	tempm->bg = (temp >= 0) ? temp : -1;
	index += (temp >= 0) ? ft_strlen(colors[temp]) : 0;
	return (str[index] == '}' ? index : 0);
}

void	colorise(t_arg *list)
{
	int		mal;
	int		i;
	char	*str;

	i = 2;
	mal = ((list->att >= 0) ? 1 : 0) + ((list->bg >= 0) ? 2 : 0)
	+ ((list->fg >= 0) ? 2 : 0) + ((list->att >= 0 && list->fg >= 0) ? 1 : 0)
	+ ((list->bg >= 0 && list->fg >= 0) ? 1 : 0);
	str = (char*)ft_memalloc((size_t)(mal + 4));
	ft_strcat(str, "\x1B[");
	list->att >= 0 ? str[i++] = (char)(list->att + '0') : 0;
	(list->att >= 0 && list->fg >= 0) ? str[i++] = ';' : 0;
	(list->fg >= 0) ? str[i++] = '3' : 0;
	(list->fg >= 0) ? str[i++] = (char)(list->fg + '0') : 0;
	(list->fg >= 0 && list->bg >= 0) ? str[i++] = ';' : 0;
	(list->bg >= 0) ? str[i++] = '4' : 0;
	(list->bg >= 0) ? str[i++] = (char)(list->bg + '0') : 0;
	str[i] = '\0';
	ft_strcat(str, "m");
	write(1, str, (size_t)mal + 3);
	ft_memdel((void**)&str);
	list->length += mal + 3;
}
