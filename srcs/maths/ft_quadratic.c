/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quadratic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:07:16 by rbourgea          #+#    #+#             */
/*   Updated: 2020/02/15 17:37:32 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"

int		ft_quadratic(double coeff[3], double *t1, double *t2)
{
	double		delta;
	double		sdelta;

	delta = coeff[1] * coeff[1] - 4 * coeff[0] * coeff[2];
	if (delta < 0)
		return (0);
	sdelta = sqrt(delta);
	*t1 = (-coeff[1] - sdelta) / (2. * coeff[0]);
	*t2 = (-coeff[1] + sdelta) / (2. * coeff[0]);
	if (delta < 0)
		return (1);
	return (2);
}
