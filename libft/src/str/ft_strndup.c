/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 11:19:32 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/08 18:30:58 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(char *todup, size_t size)
{
	char *dupped;

	if (!todup || !size)
		return (NULL);
	if (!(dupped = ft_strnew(size + 1)))
		return (NULL);
	ft_strncpy(dupped, todup, size);
	return (dupped);
}
