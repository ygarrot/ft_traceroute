/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 10:13:12 by ygarrot           #+#    #+#             */
/*   Updated: 2018/03/19 16:57:46 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		putstrnb(char *str, t_arg *list, int len, int add)
{
	int		diese;
	int		addpre;

	diese = list->flags[4];
	*str == '0' && !list->pre ? str[0] = '\0' : 0;
	addpre = (*str == '-' ? 1 : 0) - (diese && (list->conv == 1 ||
				list->conv == 4) ? 1 : 0);
	if (list->flags[0] && list->conv > 6 && !diese && *str != '-')
		ft_putstr("+");
	*str == '-' ? ft_putstr("-") : 0;
	if (list->flags[3] && !list->flags[0] && list->conv > 6 && *str != '-')
		ft_putstr(" ");
	if (list->conv == 6 || (diese && *str != '0' && (list->conv == 1
	|| list->conv == 4 || (*str && (list->conv == 2 || list->conv == 5)))))
		ft_putstr("0");
	if (list->conv == 6 || (*str && *str != '0' && (diese && list->conv == 2)))
		ft_putstr("x");
	if (*str && *str != '0' && diese && list->conv == 5)
		ft_putstr("X");
	list->pre == 1 && (list->flags[1] && !list->flags[2]) ? ft_putn_schar('0'
			, list->champ - ft_ismax(len, list->pre + addpre) - add) : 0;
	list->pre > 0 ? ft_putn_schar('0', list->pre - len + addpre) : 0;
	list->conv == 5 ? ft_capitalize(str) : 0;
	ft_putstr(*str == '-' ? &str[1] : str);
}

void		ft_noprecision(char *str, t_arg *list, int add, int len)
{
	int left;

	left = list->flags[2];
	if (list->conv > 9)
	{
		left ? ft_putnstr(str, len, list) : 0;
		ft_putn_schar(list->flags[1] && !left ? '0' : ' ', list->champ - len);
		!left ? ft_putnstr(str, len, list) : 0;
	}
	else
	{
		(left && str) ? putstrnb(str, list, len, add) : 0;
		ft_putn_schar(' ', (!list->flags[1] || list->flags[2]) ?
				list->champ - len - add : 0);
		(!left && str) ? putstrnb(str, list, len, add) : 0;
	}
	list->length = ft_ismax(list->champ, len + add);
}

void		ft_precision(char *str, t_arg *list, int add, int len)
{
	int left;
	int addpre;

	left = list->flags[2];
	addpre = (!list->pre ? 1 : 0) - ((str && *str == '-') ? 1 : 0) +
		(list->flags[4] && (list->conv == 1 || list->conv == 4) ? 1 : 0);
	if (list->conv > 9)
	{
		left ? ft_putnstr(str, list->pre, list) : 0;
		ft_putn_schar(list->flags[1] && !list->flags[3] ? '0' : ' ',
		list->champ - (list->pre < len ? list->pre : len));
		!left ? ft_putnstr(str, list->pre, list) : 0;
		list->length = list->pre < len ? list->pre : len;
	}
	else
	{
		(left && str) ? putstrnb(str, list, len, add) : 0;
		ft_putn_schar(' ', list->champ - ft_ismax(list->pre - addpre, len)
				- add);
		(!left && str) ? putstrnb(str, list, len, add) : 0;
		list->length = ft_ismax(list->pre - addpre, len) + add;
	}
	list->length = list->champ > list->length ? list->champ : list->length;
}

void		print1(char *str, t_arg *list)
{
	int len;
	int add;

	add = 0;
	add = ((!str && list->pre < 0) ? 6 : 0) + (list->conv == 6 ||
	((list->flags[4] && (list->conv == 2 || list->conv == 5)) && str &&
	*str != '0') ? 2 : 0) + ((list->flags[4] && (list->conv == 1 ||
	list->conv == 4) && str && *str != '0') ? 1 : 0) + ((list->conv > 6 &&
	list->conv < 10 && ((list->flags[0] || list->flags[3]) && str
	&& *str != '-') ? 1 : 0));
	len = (str && !list->pre && *str == '0' && (!list->flags[4] ||
				(list->conv != 1 && list->conv != 4))) ? 0 : ft_strlen(str);
	len = ((list->conv == 10 || list->conv == 11) && !*str) ? 1 : len;
	if ((list->pre == 1 && list->conv < 10) || (list->pre < 0 && list->conv >
				9) || (!list->pre && (list->conv == 10 || list->conv == 11 ||
						list->conv == 14)))
		ft_noprecision(str, list, add, len);
	else
		ft_precision(str, list, add, len);
	if (str && list->conv != 12 && list->conv != 14)
		ft_memdel((void**)&str);
}
