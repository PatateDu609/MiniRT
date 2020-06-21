/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 01:39:54 by gboucett          #+#    #+#             */
/*   Updated: 2020/06/21 22:24:36 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"

/*
** n[0] = radius / n[1] = t1 / n[2] = t2
*/

static	int		ft_solve_inter(t_sphere *sphere, t_ray *ray, t_intersect *inter)
{
	double		n[3];
	int			nb;
	double		coeff[3];
	t_vector	c_o;

	n[0] = sphere->diameter / 2.;
	ft_vector_sub(c_o, ray->origin, sphere->origin);
	coeff[0] = 1;
	coeff[1] = 2 * ft_vector_dot(ray->direct, c_o);
	coeff[2] = ft_vector_dot(c_o, c_o) - n[0] * n[0];
	if (!(nb = ft_quadratic(coeff, &n[1], &n[2])))
		return (0);
	if (n[2] <= 0)
		return (0);
	inter->param = (n[1] > 0) ? n[1] : n[2];
	return (1);
}

int				ft_resolv_sphere(void *object, t_ray *ray,
		t_intersect *intersect)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)object;
	if (!ft_solve_inter(sphere, ray, intersect))
		return (0);
	ft_ray_point(intersect->pos, ray, intersect->param);
	ft_vector_sub(intersect->normal, intersect->pos, sphere->origin);
	ft_vector_normalize(intersect->normal);
	return (1);
}
