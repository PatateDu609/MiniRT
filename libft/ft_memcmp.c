/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:52:14 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/04 21:34:52 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned int	l;
	unsigned char	*s;
	unsigned char	*o;

	if (len == 0)
		return (0);
	l = 0;
	s = (unsigned char*)s1;
	o = (unsigned char*)s2;
	while (l < len)
	{
		if (s[l] != o[l])
			return (s[l] - o[l]);
		l++;
	}
	return (0);
}
