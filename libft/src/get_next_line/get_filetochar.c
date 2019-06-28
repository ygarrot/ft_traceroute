/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_filetochar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:53:24 by tcharrie          #+#    #+#             */
/*   Updated: 2018/06/09 12:55:00 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		chachr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static t_gnl	*get_fd(t_gnl *list, int fd)
{
	if (list->fd == fd)
	{
		!list->buf ? list->buf = ft_strnew(1) : 0;
		return (list->buf ? list : NULL);
	}
	while (list->next && list->next->fd != fd)
		list = list->next;
	if (list->next)
		return (list->next);
	if (!(list->next = (t_gnl*)ft_memalloc(sizeof(t_gnl)))
			|| !(list->next->buf = ft_strnew(1)))
		return (NULL);
	list->next->fd = fd;
	return (list->next);
}

static char		*initline(t_gnl *lst, char lim)
{
	int		i;
	int		i2;
	size_t	len;
	char	*temp;

	i = chachr(lst->buf, lim);
	if (!(temp = ft_strnew(i)))
		return (NULL);
	ft_strncat(temp, lst->buf, i);
	i2 = -1;
	len = ft_strlen(&lst->buf[i]);
	while (++i2 < (int)len)
		lst->buf[i2] = lst->buf[(i + 1) + i2];
	lst->buf = ft_realloc(lst->buf, i2);
	return (temp);
}

int				get_filetochar(const int fd, char **line, char lim)
{
	static t_gnl	gl;
	t_gnl			*lst;
	int				ret;
	int				i;

	gl.fd = -1;
	lst = NULL;
	if (!gl.buf && !(gl.buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (BUFF_SIZE < 1 || !line || fd < 0 || (i = 0)
			|| !(lst = get_fd(&gl, fd)) || !lst->buf)
		return (lst && !lst->buf ? 0 : -1);
	while (!i && (ret = read(fd, gl.buf, BUFF_SIZE)) > 0)
	{
		lst->buf = ft_realloc(lst->buf, (ft_strlen(lst->buf) + ret + 1));
		ft_strncat(lst->buf, gl.buf, ret);
		i = chachr(gl.buf, lim) < ret;
	}
	if (ret < 0 || !*lst->buf)
		return (ret < 0 ? -1 : 0);
	return ((*line = initline(lst, lim)) ? 1 : -1);
}
