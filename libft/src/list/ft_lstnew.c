/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:08:17 by ygarrot           #+#    #+#             */
/*   Updated: 2017/12/05 12:57:14 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *maillon;

	maillon = NULL;
	if ((maillon = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (!content)
	{
		maillon->content = NULL;
		maillon->content_size = 0;
	}
	else
	{
		if (!(maillon->content =
					(t_list*)malloc(content_size * sizeof(content))))
		{
			free(maillon);
			maillon = NULL;
			return (NULL);
		}
		ft_memcpy(maillon->content, content, content_size);
		maillon->content_size = content_size;
	}
	maillon->next = NULL;
	return (maillon);
}
