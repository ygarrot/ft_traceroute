/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:30:25 by ygarrot           #+#    #+#             */
/*   Updated: 2017/11/13 13:04:45 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *maillon;

	if (!(lst))
		f(lst);
	else
	{
		maillon = lst;
		while (maillon)
		{
			f(maillon);
			maillon = maillon->next;
		}
	}
}
