/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 13:47:04 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/05 17:48:24 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"

typedef struct		s_getline
{
	char				*buf;
	int					fd;
	char				padding[4];
	struct s_getline	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);
int					get_next_line_b(const int fd, char **line, size_t size);
int					get_filetochar(const int fd, char **line, char c);
#endif
