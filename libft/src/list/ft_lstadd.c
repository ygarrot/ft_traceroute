/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:00:22 by ygarrot           #+#    #+#             */
/*   Updated: 2017/11/23 13:20:34 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *maillon;

	maillon = NULL;
	if (!(*alst))
		*alst = new;
	else
	{
		maillon = new;
		maillon->next = *alst;
		*alst = maillon;
	}
}
