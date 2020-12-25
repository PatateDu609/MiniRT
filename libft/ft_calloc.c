/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:53:12 by gboucett          #+#    #+#             */
/*   Updated: 2020/12/23 17:44:15 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*result;
	size_t	i;

	result = (char*)malloc(size * nitems);
	if (!result)
		return (NULL);
	i = 0;
	while (i < (nitems * size))
		result[i++] = 0;
	return (result);
}
