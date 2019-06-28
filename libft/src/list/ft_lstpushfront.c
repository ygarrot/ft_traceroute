/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:21:51 by tcharrie          #+#    #+#             */
/*   Updated: 2018/01/20 12:11:49 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpushfront(void *content, size_t content_size, t_list *begin)
{
	t_list	*new;

	if (!(new = ft_lstnewc(content, content_size)))
		return (NULL);
	if (!(begin))
		return (new);
	new->next = begin;
	return (new);
}
