/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addtofd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 13:45:30 by tcharrie          #+#    #+#             */
/*   Updated: 2018/04/21 13:46:46 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_addtofd(char *str, int fd)
{
	int	i;

	if (!str)
		return (-1);
	i = ft_strlen(str);
	while (i-- > 0)
		if (ioctl(fd, TIOCSTI, &str[i]) == -1)
			return (-1);
	return (1);
}
