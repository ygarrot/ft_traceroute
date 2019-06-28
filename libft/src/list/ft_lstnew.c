/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:08:17 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/12 12:42:21 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *maillon;

	maillon = (t_list*)ft_memalloc(sizeof(t_list));
	if (!maillon || !content)
		return (NULL);
	maillon->content = malloc(content_size);
	if (!maillon->content)
	{
		ft_memdel((void**)&maillon);
		return (NULL);
	}
	ft_memcpy(maillon->content, content, content_size);
	maillon->content_size = content_size;
	return (maillon);
}
