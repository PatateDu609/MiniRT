/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:22:37 by gboucett          #+#    #+#             */
/*   Updated: 2020/12/23 17:43:24 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btree_create_node(void *item)
{
	t_btree		*node;

	if (!item)
		return (NULL);
	node = (t_btree *)ft_calloc(1, sizeof(t_btree));
	if (!node)
		return (NULL);
	node->item = item;
	return (node);
}
