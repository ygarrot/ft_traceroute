/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 13:03:09 by tcharrie          #+#    #+#             */
/*   Updated: 2018/05/08 12:57:21 by tcharrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	btree_level_count(t_btree *root)
{
	int	size_l;
	int	size_r;

	size_l = 0;
	size_r = 0;
	if (!root)
		return (0);
	if (root->left)
		size_l = LV(root->left);
	if (root->right)
		size_r = LV(root->right);
	if (size_l > size_r)
		return (size_l + 1);
	return (size_r + 1);
}
