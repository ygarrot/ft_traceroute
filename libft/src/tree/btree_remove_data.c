/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_remove_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcharrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 14:55:48 by tcharrie          #+#    #+#             */
/*   Updated: 2019/01/25 15:31:42 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	btree_remove_data_mid(t_btree **root, t_btree *trade,
		void (*del)(void*))
{
	if (root[0]->parent && root[0]->parent->right == root[0])
		root[0]->parent->right = trade;
	else if (root[0]->parent)
		root[0]->parent->left = trade;
	root[0]->left->parent = trade;
	trade->left = root[0]->left;
	trade->parent = root[0]->parent;
	del(root[0]->item);
	free(root[0]);
	root[0] = trade;
}

static void	btree_remove_data_harsh(t_btree **root, void (*del)(void*))
{
	t_btree	*trade;

	trade = root[0]->right;
	if (!trade->left)
	{
		btree_remove_data_mid(root, trade, del);
		return ;
	}
	while (trade->left)
		trade = trade->left;
	trade->parent->left = trade->right;
	if (trade->right)
		trade->right->parent = trade->parent;
	if (root[0]->parent && root[0]->parent->right == root[0])
		root[0]->parent->right = trade;
	else if (root[0]->parent)
		root[0]->parent->left = trade;
	root[0]->right->parent = trade;
	root[0]->left->parent = trade;
	trade->parent = root[0]->parent;
	del(root[0]->item);
	free(root[0]);
	root[0] = trade;
}

static void	btree_remove_data_easy(t_btree **root, void (*del)(void*))
{
	t_btree	*trade;
	t_btree	*tmp;

	tmp = root[0];
	if (!root[0]->left)
		trade = root[0]->right;
	else
		trade = root[0]->left;
	if (root[0]->parent && root[0]->parent->left == root[0])
		root[0]->parent->left = trade;
	else if (root[0]->parent)
		root[0]->parent->right = trade;
	if (trade)
		trade->parent = tmp->parent;
	del(tmp->item);
	free(tmp);
	root[0] = trade;
}

void		btree_remove_data(t_btree **root, void *data,
		int (*cmpf)(void*, void*), void (*del)(void *))
{
	int		val;

	if (!root || !*root)
		return ;
	val = cmpf(data, root[0]->item);
	if (val < 0)
		btree_remove_data(&(root[0]->left), data, cmpf, del);
	else if (val >= 0)
		btree_remove_data(&(root[0]->right), data, cmpf, del);
	else if (!root[0]->left || !root[0]->right)
		btree_remove_data_easy(root, del);
	else
		btree_remove_data_harsh(root, del);
}
