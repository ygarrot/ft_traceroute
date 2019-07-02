/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:16:59 by ygarrot           #+#    #+#             */
/*   Updated: 2018/06/20 18:14:35 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *maillon;

	if (!alst)
		return ;
	maillon = *alst;
	if (!maillon)
		return ;
	del(maillon->content, maillon->content_size);
	free(maillon);
	*alst = NULL;
}
