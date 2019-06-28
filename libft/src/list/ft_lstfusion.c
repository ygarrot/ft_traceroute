/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfusion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 16:16:30 by tcharrie          #+#    #+#             */
/*   Updated: 2018/06/20 18:30:05 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstfusion_(t_list *left, t_list *right, int (*cmp)(void *,
		void *), void (*del)(void*, size_t))
{
	t_list	*next;
	int		val;
	t_list	*todel;

	while (right && left && left->next)
	{
		val = cmp(left->next->content, right->content);
		todel = (val == 0 ? right : 0);
		if (val == 0)
			right = right->next;
		else if (val > 0)
		{
			next = right->next;
			right->next = left->next;
			left->next = right;
			left = right;
			right = next;
		}
		else
			left = left->next;
		ft_lstdelone(&todel, del);
	}
	ft_lstpushback(&left, right);
}

void		ft_lstfusion(t_list **left, t_list *right, int (*cmp)(void *,
			void *), void (*del)(void *, size_t))
{
	t_list	*next;

	if (!left || !right)
		return ;
	if (!*left)
	{
		*left = right;
		return ;
	}
	if (cmp(right->content, (*left)->content) < 0)
	{
		next = right->next;
		right->next = *left;
		*left = right;
		right = next;
	}
	while (right && cmp(right->content, (*left)->content) == 0)
	{
		next = right->next;
		ft_lstdelone(&right, del);
		right = next;
	}
	ft_lstfusion_(*left, right, cmp, del);
}
