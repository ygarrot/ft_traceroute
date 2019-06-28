/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:11:01 by tcharrie          #+#    #+#             */
/*   Updated: 2018/01/17 14:11:14 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_listsorted(t_list *lst, int (*cmp)(void *, void *))
{
	while (lst && lst->next)
	{
		if (!cmp(lst->content, lst->next->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}

static t_list	*ft_swap(t_list *prev, t_list *lst, t_list *ne)
{
	if (prev)
		prev->next = ne;
	lst->next = ne->next;
	ne->next = lst;
	if (prev)
		return (prev);
	return (ne);
}

static void		ft_aux(t_list *tmp, t_list *prec, int (*cmp)(void *, void *))
{
	t_list	*prev;

	prev = prec;
	while (tmp && tmp->next)
	{
		if (!(cmp(tmp->content, tmp->next->content)))
		{
			ft_swap(prev, tmp, tmp->next);
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

t_list			*ft_lstsort(t_list *lst, int (*cmp)(void *, void *))
{
	t_list	*suiv;
	t_list	*tmp;
	t_list	*begin;

	if (!lst || !(lst->next))
		return (lst);
	begin = lst;
	while (!ft_listsorted(begin, cmp))
	{
		tmp = begin;
		suiv = tmp->next;
		if (!cmp(tmp->content, suiv->content))
		{
			begin = suiv;
			tmp->next = suiv->next;
			suiv->next = tmp;
		}
		ft_aux(begin->next, begin, cmp);
	}
	return (begin);
}
