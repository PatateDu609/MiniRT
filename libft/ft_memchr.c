/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:35:38 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/04 20:50:48 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char	*str;
	unsigned int	i;

	str = (unsigned char*)s;
	i = 0;
	while (i < len)
	{
		if (str[i++] == (unsigned char)c)
			return (str + i - 1);
	}
	return (NULL);
}
