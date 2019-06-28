/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushsort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 16:17:15 by tcharrie          #+#    #+#             */
/*   Updated: 2018/06/17 16:17:15 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstpushsort(t_list **lst, t_list *new, int (*cmp)(void *, void*))
{
	int		i;
	t_list	*tmp;

	if (!lst || !new)
		return (!new ? 0 : -1);
	if (!*lst)
	{
		*lst = new;
		return (0);
	}
	if ((i = cmp(new->content, lst[0]->content)) <= 0)
	{
		new->next = lst[0];
		lst[0] = new;
		return (0);
	}
	tmp = lst[0];
	while (tmp->next && (i = tmp->next ?
			cmp(tmp->next->content, new->content) : 0) > 0)
		tmp = tmp->next;
	new->next = tmp->next;
	tmp->next = new;
	return (0);
}
