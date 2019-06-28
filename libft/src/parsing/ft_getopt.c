/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 12:37:00 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/28 12:32:42 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getopt(int argc, char *argv[],
		const char *optstring, int *nb)
{
	int		ret;
	int		i2;
	int		i;

	ret = 0;
	i = 0;
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "--"))
			break ;
		if (*argv[i] == '-')
		{
			i2 = 0;
			while (argv[i][++i2])
			{
				if (ft_isin((char)(argv[i][i2]), (char*)optstring))
					ret |= (1 << ft_charchr(argv[i][i2], (char*)optstring));
			}
		}
		else
			(*nb)++;
	}
	return (ret);
}
