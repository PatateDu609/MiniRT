/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_suffix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:24:34 by gboucett          #+#    #+#             */
/*   Updated: 2020/07/07 18:26:45 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_suffix(t_btree *root, void (*f)(void *))
{
	if (!root || !f)
		return ;
	ft_btree_apply_suffix(root->left, f);
	ft_btree_apply_suffix(root->right, f);
	f(root->item);
}
