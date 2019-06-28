/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getoptvalue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:58:45 by ygarrot           #+#    #+#             */
/*   Updated: 2019/04/29 16:24:26 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getoptvalue(int argc, char *argv[],
		const char *optstring, char **opts)
{
	int		ret;
	int		i2;
	int		last;
	int		i;

	ret = 0;
	i = 0;
	last = 0;
	while (++i < argc && ft_strcmp(argv[i], "--"))
	{
		if (*argv[i] == '-')
		{
			i2 = 0;
			while (argv[i][++i2])
			{
				if (ft_isin((char)(argv[i][i2]), (char*)optstring))
					last = ft_charchr(argv[i][i2], (char*)optstring);
				ret |= (1 << last);
			}
		}
		else
			opts[last] = argv[i];
	}
	return (ret);
}
