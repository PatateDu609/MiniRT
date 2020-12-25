/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:01:07 by gboucett          #+#    #+#             */
/*   Updated: 2020/07/07 18:26:39 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_infix(t_btree *root, void (*f)(void *))
{
	if (!root || !f)
		return ;
	ft_btree_apply_infix(root->left, f);
	f(root->item);
	ft_btree_apply_infix(root->right, f);
}
