/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ternary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:54:06 by gboucett          #+#    #+#             */
/*   Updated: 2020/12/23 18:38:16 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_ternary(int test, void *a, void *b)
{
	if (test)
		return (a);
	else
		return (b);
}

int	ft_ternaryi(int test, int a, int b)
{
	return (ft_ternaryl(test, a, b));
}

long	ft_ternaryl(int test, long a, long b)
{
	return (ft_ternaryul(test, a, b));
}

unsigned long	ft_ternaryul(int test, unsigned long a, unsigned long b)
{
	return ((unsigned long)ft_ternary(test, (void *)a, (void *)b));
}

double	ft_ternaryd(int test, double a, double b)
{
	if (test)
		return (a);
	else
		return (b);
}
