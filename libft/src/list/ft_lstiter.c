/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:30:25 by ygarrot           #+#    #+#             */
/*   Updated: 2019/05/16 13:38:36 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (!lst)
		return ;
	f(lst);
	ft_lstiter(lst->next, f);
}

void	ft_lstiter_s(t_list *lst, void *env, void (*f)(t_list *elem, void *env))
{
	if (!lst)
		return ;
	f(lst, env);
	ft_lstiter_s(lst->next, env, f);
}
