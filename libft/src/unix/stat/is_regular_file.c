/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_regular_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 12:21:53 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/28 19:38:48 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>

int	is_regular_file(int fd)
{
	struct stat	path_stat;

	fstat(fd, &path_stat);
	return (S_ISREG(path_stat.st_mode));
}
