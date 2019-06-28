/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:26:04 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/11 12:32:02 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cpy(char *from, char *to)
{
	char	buff[201];
	int		fdfrom;
	int		fdto;
	int		re;

	if (!to || !from)
		return (0);
	if ((fdto = open(to, O_CREAT | O_WRONLY)) == -1)
		return (-1);
	if ((fdfrom = open(to, O_RDONLY)) == -1)
		return (-1);
	while ((re = read(fdfrom, buff, 200)) > 0)
		write(fdto, buff, re);
	if (close(fdto) == -1)
		re = -1;
	if (close(fdfrom) == -1)
		re = -1;
	return (re < 0 ? -1 : 0);
}
