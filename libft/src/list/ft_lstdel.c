/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:45:08 by ygarrot           #+#    #+#             */
/*   Updated: 2017/11/13 13:04:05 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *maillon;

	maillon = *alst;
	while (maillon)
	{
		del(maillon->content, maillon->content_size);
		free(maillon);
		maillon = maillon->next;
	}
	*alst = NULL;
}
