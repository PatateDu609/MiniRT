/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 01:52:05 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/17 23:41:47 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"

int		ft_resolv_plane(void *object, t_ray *ray, t_intersect *intersect)
{
	t_plane		*plane;
	t_vector	l0p0;

	plane = (t_plane *)object;
	memcpy(intersect->normal, plane->normal, sizeof(t_vector));
	ft_vector_sub(l0p0, ray->origin, plane->coord);
	intersect->param = -ft_vector_dot(l0p0, plane->normal) /
						ft_vector_dot(ray->direct, plane->normal);
	if (intersect->param < 0)
		return (0);
	ft_ray_point(intersect->pos, ray, intersect->param);
	return (1);
}
