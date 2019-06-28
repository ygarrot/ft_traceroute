/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:48:02 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/05 17:48:04 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		chachr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
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

static char		*initline(t_gnl *lst)
{
	int		i;
	int		i2;
	size_t	len;
	char	*temp;

	i = chachr(lst->buf);
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

int				get_next_line_b(const int fd, char **line, size_t buff_size)
{
	static t_gnl	gl;
	t_gnl			*lst;
	int				ret;
	int				i;

	gl.fd = -1;
	lst = NULL;
	if (!gl.buf && !(gl.buf = ft_strnew(buff_size)))
		return (-1);
	if (buff_size < 1 || !line || fd < 0 || (i = 0)
			|| !(lst = get_fd(&gl, fd)) || !lst->buf)
		return (lst && !lst->buf ? 0 : -1);
	while (!i && (ret = read(fd, gl.buf, buff_size)) > 0)
	{
		lst->buf = ft_realloc(lst->buf, (ft_strlen(lst->buf) + ret + 1));
		ft_strncat(lst->buf, gl.buf, ret);
		i = chachr(gl.buf) < ret;
	}
	if (ret < 0 || !*lst->buf)
		return (ret < 0 ? -1 : 0);
	return ((*line = initline(lst)) ? 1 : -1);
}
