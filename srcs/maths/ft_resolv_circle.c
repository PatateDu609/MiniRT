/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv_circle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 21:07:50 by gboucett          #+#    #+#             */
/*   Updated: 2020/02/29 19:15:59 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"
#include "debug.h"

int		ft_resolv_circle(void *object, t_ray *ray, t_intersect *intersect)
{
	t_circle		*circle;
	t_plane			plane;
	t_intersect		pinter;
	t_vector		c_p;

	circle = (t_circle *)object;
	ft_memcpy(plane.coord, circle->coord, sizeof(t_vector));
	ft_memcpy(plane.normal, circle->normal, sizeof(t_vector));
	if (!ft_resolv_plane(&plane, ray, &pinter))
		return (0);
	ft_vector_sub(c_p, pinter.pos, circle->coord);
	if (ft_vector_norm2(c_p) > pow(circle->diameter / 2, 2))
		return (0);
	ft_memcpy(intersect, &pinter, sizeof(t_intersect));
	return (1);
}
