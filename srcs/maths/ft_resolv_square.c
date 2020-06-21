/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 01:52:34 by gboucett          #+#    #+#             */
/*   Updated: 2020/06/19 22:38:42 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"
#include <float.h>
#include "debug.h"

void		ft_vector_new(t_vector new, double x, double y, double z)
{
	new[0] = x;
	new[1] = y;
	new[2] = z;
}

/*
** n[0] = a / n[1] = b / n[2] = t1 / n[3] = t2
*/

int			ft_resolv_square(void *object, t_ray *ray, t_intersect *intersect)
{
	double		n[4];
	t_vector	d;
	t_square	*sq;
	t_vector	result;

	sq = (t_square *)object;
	ft_vector_sub(result, ray->origin, sq->coord);
	n[0] = ft_vector_dot(result, sq->normal);
	n[1] = ft_vector_dot(ray->direct, sq->normal);
	if (fabs(n[1]) < 1e-6 || (n[0] < 0 && n[1] < 0) || (n[0] > 0 && n[1] > 0))
		return (0);
	n[2] = -n[0] / n[1];
	ft_vector_mult_lambda(result, ray->direct, n[2]);
	ft_vector_add(result, result, ray->origin);
	ft_vector_sub(d, result, sq->coord);
	n[3] = sq->size / 2;
	if (fabs(d[0]) > n[3] || fabs(d[1]) > n[3] || fabs(d[2]) > n[3])
		return (0);
	intersect->param = n[2];
	ft_ray_point(intersect->pos, ray, n[2]);
	return (1);
}
