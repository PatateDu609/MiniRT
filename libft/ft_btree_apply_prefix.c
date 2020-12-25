/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_prefix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:28:37 by gboucett          #+#    #+#             */
/*   Updated: 2020/07/07 18:49:33 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_btree_apply_prefix(t_btree *root, void (*f)(void *))
{
	if (!root || !f)
		return ;
	f(root->item);
	ft_btree_apply_prefix(root->left, f);
	ft_btree_apply_prefix(root->right, f);
}
