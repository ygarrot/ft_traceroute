/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:39:52 by tcharrie          #+#    #+#             */
/*   Updated: 2018/01/18 14:23:41 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static t_list	*ft_lstlast(t_list *start)
{
	t_list	*tmp;

	if (!start)
		return (NULL);
	while (start->next && start->next->next)
		start = start->next;
	if (start->next)
		tmp = start->next;
	else
		return (NULL);
	start->next = NULL;
	return (tmp);
}

t_list			*ft_lstreverse(t_list **begin)
{
	t_list	*beg;
	t_list	*tmp;

	if (!begin)
		return (NULL);
	if (!*begin)
		return (*begin);
	if (!(*begin)->next)
		return (NULL);
	beg = ft_lstlast(*begin);
	while ((tmp = ft_lstlast(*begin)))
		ft_lstpushback(&beg, tmp);
	if (*begin)
		ft_lstpushback(&beg, *begin);
	if (!beg)
		return (NULL);
	*begin = beg;
	return (beg);
}
