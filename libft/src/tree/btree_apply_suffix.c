/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 16:01:54 by tcharrie          #+#    #+#             */
/*   Updated: 2018/06/03 14:54:02 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_apply_suffix(t_btree *root, void (*apply)(void*))
{
	if (!root)
		return ;
	if (root->left)
		btree_apply_suffix(root->left, apply);
	if (root->right)
		btree_apply_suffix(root->right, apply);
	apply(root->item);
}
