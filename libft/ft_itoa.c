/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:34:38 by gboucett          #+#    #+#             */
/*   Updated: 2020/12/24 21:06:04 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(unsigned int n, size_t size)
{
	if (n == 0 && !size)
		return (1);
	else if (n == 0)
		return (size);
	return (ft_size(n / 10, size + 1));
}

char	*ft_itoa(int n)
{
	char			*result;
	size_t			size;
	unsigned int	nbr;

	nbr = ft_ternaryi(n < 0, -n, n);
	size = ft_size(nbr, ft_ternaryi(n < 0, 1, 0));
	result = (char *)malloc(size + 1);
	if (!result)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	result[size] = 0;
	while (size-- > 1)
	{
		result[size] = '0' + nbr % 10;
		nbr /= 10;
	}
	if (n >= 0)
		result[0] = nbr + '0';
	return (result);
}
