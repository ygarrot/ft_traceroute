/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremoveif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:29:48 by tcharrie          #+#    #+#             */
/*   Updated: 2018/01/17 15:42:16 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremoveifaux(t_list *tmp, int (*cmp)(void *, size_t),
		void (*del)(void *, size_t))
{
	t_list	*erase;

	if (!tmp)
		return ;
	while (tmp->next)
	{
		while (tmp->next && cmp(tmp->next->content, tmp->next->content_size))
		{
			erase = tmp->next;
			tmp->next = tmp->next->next;
			ft_lstdelone(&erase, del);
		}
		if (tmp->next)
			tmp = tmp->next;
	}
}

t_list	*ft_lstremoveif(t_list **begin, int (*cmp)(void *, size_t t),
		void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (!begin)
		return (NULL);
	if (!*begin)
		return (*begin);
	while (*begin && cmp((*begin)->content, (*begin)->content_size))
	{
		tmp = *begin;
		*begin = tmp->next;
		ft_lstdelone(&tmp, del);
	}
	ft_lstremoveifaux(*begin, cmp, del);
	return (*begin);
}
