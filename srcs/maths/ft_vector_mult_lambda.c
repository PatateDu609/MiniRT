/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_mult_lambda.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teyber <teyber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 23:36:18 by teyber            #+#    #+#             */
/*   Updated: 2020/01/02 23:37:06 by teyber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"

void		ft_vector_mult_lambda(t_vector result, t_vector a, double lambda)
{
	result[0] = lambda * a[0];
	result[1] = lambda * a[1];
	result[2] = lambda * a[2];
}
