/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 01:48:50 by gboucett          #+#    #+#             */
/*   Updated: 2020/06/19 23:49:31 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"
#include "debug.h"

int		ft_resolv_cylinder_4(t_vector b[2], t_ray *ray,
	t_intersect *intersect, t_cylinder *cylinder)
{
	ft_ray_point(intersect->pos, ray, intersect->param);
	ft_vector_sub(b[2], intersect->pos, cylinder->coord);
	if (ft_vector_dot(cylinder->orient, b[2]) < 0)
		return (0);
	ft_vector_mult_lambda(b[1], cylinder->orient, cylinder->height);
	ft_vector_add(b[1], b[1], cylinder->coord);
	ft_vector_sub(b[2], intersect->pos, b[1]);
	if (ft_vector_dot(cylinder->orient, b[2]) > 0)
		return (0);
	ft_vector_sub(b[1], intersect->pos, cylinder->coord);
	ft_vector_mult_lambda(b[2], cylinder->orient,
		ft_vector_dot(cylinder->orient, b[1]));
	ft_vector_sub(intersect->normal, b[1], b[2]);
	ft_vector_normalize(intersect->normal);
	return (1);
}

int		ft_resolv_cylinder_3(double coeff[3], double t1, double t2,
			t_intersect *intersect)
{
	if (!(ft_quadratic(coeff, &t1, &t2)))
		return (0);
	if (t2 < 0)
		return (0);
	intersect->param = (t1 < 0) ? t2 : t1;
	return (1);
}

int		ft_resolv_cylinder_2(t_vector cross, t_vector cross2,
			t_cylinder *cylinder, double coeff[3])
{
	coeff[0] = ft_vector_dot(cross, cross);
	coeff[1] = 2 * ft_vector_dot(cross, cross2);
	coeff[2] = ft_vector_dot(cross2, cross2) - (pow(cylinder->diameter / 2, 2) *
		ft_vector_dot(cylinder->orient, cylinder->orient));
	return (1);
}

/*
**	n[0] = c_o / n[1] = cross / n[2] = cross2
*/

int		ft_resolv_cylinder(void *object, t_ray *ray, t_intersect *intersect)
{
	t_cylinder	*cylinder;
	double		t[2];
	double		coeff[3];
	t_vector	n[3];
	t_vector	b[2];

	cylinder = (t_cylinder *)object;
	ft_vector_sub(n[0], ray->origin, cylinder->coord);
	ft_vector_cross(n[1], ray->direct, cylinder->orient);
	ft_vector_cross(n[2], n[0], cylinder->orient);
	ft_resolv_cylinder_2(n[1], n[2], cylinder, coeff);
	t[0] = 0;
	t[1] = 0;
	if (ft_resolv_cylinder_3(coeff, t[0], t[1], intersect) == 0)
		return (0);
	return (ft_resolv_cylinder_4(b, ray, intersect, cylinder));
}
