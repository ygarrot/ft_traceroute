/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dblechar_tab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 11:56:54 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/13 11:38:43 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_dblechar_tab(char **dbltab)
{
	int	i;

	i = 0;
	if (!dbltab)
		return ;
	while (dbltab[i])
		ft_memdel((void**)&dbltab[i++]);
	ft_memdel((void**)&dbltab[i]);
	ft_memdel((void**)&dbltab);
}
