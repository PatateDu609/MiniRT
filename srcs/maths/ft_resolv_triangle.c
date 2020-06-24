/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 01:52:46 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/20 00:12:04 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"
#include <float.h>

void	ft_resolv_triangle_2(t_triangle *triangle,
			t_vector edges[2], t_vector pvec, t_ray *ray)
{
	ft_vector_sub(edges[0], triangle->coord[1], triangle->coord[0]);
	ft_vector_sub(edges[1], triangle->coord[2], triangle->coord[0]);
	ft_vector_cross(pvec, ray->direct, edges[1]);
}

/*
**	n[0] = det / n[1] = u / n[2] = v
*/

int		ft_resolv_triangle(void *object, t_ray *ray, t_intersect *intersect)
{
	t_triangle		*triangle;
	t_vector		edges[2];
	t_vector		pvec;
	t_vector		tvec;
	double			n[3];

	triangle = (t_triangle *)object;
	ft_resolv_triangle_2(triangle, edges, pvec, ray);
	if (fabs(n[0] = ft_vector_dot(edges[0], pvec)) < DBL_EPSILON)
		return (0);
	n[0] = 1. / n[0];
	ft_vector_sub(tvec, ray->origin, triangle->coord[0]);
	n[1] = ft_vector_dot(tvec, pvec) * n[0];
	if (n[1] < 0 || n[1] > 1)
		return (0);
	ft_vector_cross(pvec, tvec, edges[0]);
	n[2] = ft_vector_dot(ray->direct, pvec) * n[0];
	if (n[2] < 0 || n[2] + n[1] > 1)
		return (0);
	intersect->param = ft_vector_dot(edges[1], pvec) * n[0];
	ft_ray_point(intersect->pos, ray, intersect->param);
	ft_vector_cross(intersect->normal, edges[0], edges[1]);
	ft_vector_normalize(intersect->normal);
	return (1);
}
