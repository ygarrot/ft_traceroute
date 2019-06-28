/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:51:38 by tcharrie          #+#    #+#             */
/*   Updated: 2019/01/25 15:48:29 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	int		val;

	if (!root)
		return (0);
	val = cmpf(data_ref, root->item);
	if (!val)
		return (root->item);
	else if (val >= 0)
		return (btree_search_item(root->right, data_ref, cmpf));
	else
		return (btree_search_item(root->left, data_ref, cmpf));
}
