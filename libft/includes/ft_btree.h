/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:42:16 by tcharrie          #+#    #+#             */
/*   Updated: 2018/06/02 15:10:08 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H
# define MAX(x, y) x > y ? x : y
# define LV(x) btree_level_count(x)
# define INS(x, y, z) btree_insert_data(x, y, z)
# include <stdlib.h>

typedef struct	s_btree
{
	struct s_btree	*parent;
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}				t_btree;

t_btree			*btree_create_node(void *item);
void			btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void			btree_apply_infix(t_btree *root, void (*applyf)(void *));
void			btree_apply_suffix(t_btree *root, void (*applyf)(void *));

int				btree_insert_data(t_btree **root, void *item, int (*cmpf)
		(void *, void *), void (*del)(void *item));
void			btree_remove_data(t_btree **root, void *data, int (*cmpf)
		(void *, void *), void (*del)(void *));

void			*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *));
int				btree_level_count(t_btree *root);

#endif
