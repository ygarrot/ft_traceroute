/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:35:57 by ygarrot           #+#    #+#             */
/*   Updated: 2018/01/11 17:07:29 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *maillon;
	t_list *buffer;
	t_list *begin;

	if (!lst || !f)
		return (0);
	maillon = f(lst);
	if ((begin = ft_lstnew(maillon->content, maillon->content_size)))
	{
		buffer = begin;
		lst = lst->next;
		while (lst)
		{
			maillon = f(lst);
			if (!(buffer->next = ft_lstnew(maillon->content,
							maillon->content_size)))
				return (0);
			buffer = buffer->next;
			lst = lst->next;
		}
	}
	return (begin);
}
