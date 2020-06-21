/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:53:12 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/06 21:37:23 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*result;
	size_t	i;

	if (!(result = (char*)malloc(size * nitems)))
		return (NULL);
	i = 0;
	while (i < (nitems * size))
		result[i++] = 0;
	return (result);
}
