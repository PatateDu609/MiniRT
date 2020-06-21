/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:29:56 by gboucett          #+#    #+#             */
/*   Updated: 2020/03/04 19:45:07 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"
#include "debug.h"

int		ft_resolv_object(t_element *object, t_ray *ray, t_intersect *intersect)
{
	int		id;
	int		(*ft_resolv[7])(void *, t_ray *, t_intersect *);
	int		result;

	if ((id = ft_check_id(object->id)) == FT_PARSE_DEFAULT ||
		id == FT_PARSE_LIGHT ||
		id == FT_PARSE_RESOLUTION ||
		id == FT_PARSE_AMBIENT_LIGHT ||
		id == FT_PARSE_CAMERA)
		return (0);
	ft_resolv[FT_PARSE_SPHERE - 4] = ft_resolv_sphere;
	ft_resolv[FT_PARSE_PLANE - 4] = ft_resolv_plane;
	ft_resolv[FT_PARSE_CYLINDER - 4] = ft_resolv_cylinder;
	ft_resolv[FT_PARSE_TRIANGLE - 4] = ft_resolv_triangle;
	ft_resolv[FT_PARSE_SQUARE - 4] = ft_resolv_square;
	ft_resolv[FT_PARSE_CIRCLE - 4] = ft_resolv_circle;
	ft_resolv[FT_PARSE_ELLIPSOID - 4] = ft_resolv_ellipsoid;
	result = ft_resolv[id - 4](object->content, ray, intersect);
	if (result)
		intersect->element = object;
	return (result);
}
