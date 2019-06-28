/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 12:22:07 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/07 16:01:10 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int	is_directory(int fd)
{
	struct stat statbuf;

	if (fstat(fd, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}

int	is_directory_str(char *str)
{
	int	fd;
	int	ret;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (-1);
	ret = is_directory(fd);
	close(fd);
	return (ret);
}
