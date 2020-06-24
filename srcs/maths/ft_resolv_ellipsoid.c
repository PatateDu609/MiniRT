/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv_ellipsoid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:06:38 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/20 23:46:47 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"

int		ft_resolv_ellipsoid_2(t_ellipsoid *ellipsoid, double n[5])
{
	n[0] = ellipsoid->coeffs[0] * ellipsoid->coeffs[0];
	n[1] = ellipsoid->coeffs[1] * ellipsoid->coeffs[1];
	n[2] = ellipsoid->coeffs[2] * ellipsoid->coeffs[2];
	return (1);
}

/*
** n[0] = a2 / n[1] = b2 / n[2] = c2 / n[3] = t1 / n[4] = t2
*/

int		ft_resolv_ellipsoid(void *object, t_ray *ray, t_intersect *intersect)
{
	t_ellipsoid		*ellipsoid;
	t_vector		coeffs;
	double			n[5];
	t_vector		el_cam;

	ellipsoid = (t_ellipsoid *)object;
	ft_resolv_ellipsoid_2(ellipsoid, n);
	ft_vector_sub(el_cam, ray->origin, ellipsoid->coord);
	coeffs[0] = (ray->direct[0] * ray->direct[0] / n[0]) + (ray->direct[1] *
		ray->direct[1] / n[1]) + (ray->direct[2] * ray->direct[2] / n[2]);
	coeffs[1] = 2 * ((el_cam[0] * ray->direct[0] / n[0]) + (el_cam[1] *
		ray->direct[1] / n[1]) + (el_cam[2] * ray->direct[2] / n[2]));
	coeffs[2] = ((el_cam[0] * el_cam[0] / n[0]) + (el_cam[1] * el_cam[1] / n[1])
		+ (el_cam[2] * el_cam[2] / n[2])) - 1;
	if (!ft_quadratic(coeffs, &n[3], &n[4]))
		return (0);
	if (n[4] < 0)
		return (0);
	intersect->param = (n[3] > 0) ? n[3] : n[4];
	ft_ray_point(intersect->pos, ray, intersect->param);
	intersect->normal[0] = 2 * intersect->pos[0] / n[0];
	intersect->normal[1] = 2 * intersect->pos[1] / n[1];
	intersect->normal[2] = 2 * intersect->pos[2] / n[2];
	return (1);
}
