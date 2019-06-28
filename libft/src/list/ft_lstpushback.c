/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:52:09 by tcharrie          #+#    #+#             */
/*   Updated: 2018/01/17 15:14:03 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstpushback(t_list **left, t_list *right)
{
	t_list	*tmp;

	if (!left)
		return ;
	if (!(tmp = *left))
		*left = right;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
		tmp->next = right;
}
