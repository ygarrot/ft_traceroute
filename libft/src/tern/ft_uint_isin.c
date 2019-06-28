/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_isin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 10:56:05 by ygarrot           #+#    #+#             */
/*   Updated: 2019/01/05 11:15:39 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_uint_isin(unsigned int tofind, unsigned int *tab, int size)
{
	while (size && tofind != tab[size - 1])
		size--;
	return (size);
}
