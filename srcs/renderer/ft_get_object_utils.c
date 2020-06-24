/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_object_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:50:23 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/23 23:02:13 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_renderer.h"

#ifndef BONUS

unsigned int	ft_get_object_color(t_element *element)
{
	unsigned int	(*ft_get_truc_color[7])(void *);
	int				id;

	if ((id = ft_check_id(element->id)) == FT_PARSE_DEFAULT ||
		id == FT_PARSE_LIGHT ||
		id == FT_PARSE_CAMERA ||
		id == FT_PARSE_AMBIENT_LIGHT ||
		id == FT_PARSE_RESOLUTION)
		return (0);
	ft_get_truc_color[FT_PARSE_CYLINDER - 4] = ft_get_cylinder_color;
	ft_get_truc_color[FT_PARSE_TRIANGLE - 4] = ft_get_triangle_color;
	ft_get_truc_color[FT_PARSE_SQUARE - 4] = ft_get_square_color;
	ft_get_truc_color[FT_PARSE_PLANE - 4] = ft_get_plane_color;
	ft_get_truc_color[FT_PARSE_SPHERE - 4] = ft_get_sphere_color;
	return (ft_get_truc_color[id - 4](element->content));
}

#else

unsigned int	ft_get_object_color(t_element *element)
{
	unsigned int	(*ft_get_truc_color[7])(void *);
	int				id;

	if ((id = ft_check_id(element->id)) == FT_PARSE_DEFAULT ||
		id == FT_PARSE_LIGHT ||
		id == FT_PARSE_CAMERA ||
		id == FT_PARSE_AMBIENT_LIGHT ||
		id == FT_PARSE_RESOLUTION)
		return (0);
	ft_get_truc_color[FT_PARSE_CYLINDER - 4] = ft_get_cylinder_color;
	ft_get_truc_color[FT_PARSE_TRIANGLE - 4] = ft_get_triangle_color;
	ft_get_truc_color[FT_PARSE_SQUARE - 4] = ft_get_square_color;
	ft_get_truc_color[FT_PARSE_PLANE - 4] = ft_get_plane_color;
	ft_get_truc_color[FT_PARSE_SPHERE - 4] = ft_get_sphere_color;
	ft_get_truc_color[FT_PARSE_CIRCLE - 4] = ft_get_circle_color;
	ft_get_truc_color[FT_PARSE_ELLIPSOID - 4] = ft_get_ellipsoid_color;
	return (ft_get_truc_color[id - 4](element->content));
}

double			ft_get_object_shiny(t_element *element)
{
	double	(*ft_get_truc_shiny[7])(void *);
	int		id;

	if ((id = ft_check_id(element->id)) == FT_PARSE_DEFAULT ||
		id == FT_PARSE_LIGHT ||
		id == FT_PARSE_CAMERA ||
		id == FT_PARSE_AMBIENT_LIGHT ||
		id == FT_PARSE_RESOLUTION)
		return (0);
	ft_get_truc_shiny[FT_PARSE_CYLINDER - 4] = ft_get_cylinder_shiny;
	ft_get_truc_shiny[FT_PARSE_TRIANGLE - 4] = ft_get_triangle_shiny;
	ft_get_truc_shiny[FT_PARSE_SQUARE - 4] = ft_get_square_shiny;
	ft_get_truc_shiny[FT_PARSE_PLANE - 4] = ft_get_plane_shiny;
	ft_get_truc_shiny[FT_PARSE_SPHERE - 4] = ft_get_sphere_shiny;
	ft_get_truc_shiny[FT_PARSE_CIRCLE - 4] = ft_get_circle_shiny;
	ft_get_truc_shiny[FT_PARSE_ELLIPSOID - 4] = ft_get_ellipsoid_shiny;
	return (ft_get_truc_shiny[id - 4](element->content));
}

unsigned int	ft_get_object_spec_color(t_element *element)
{
	unsigned int	(*get_truc_spec_color[7])(void *);
	int				id;

	if ((id = ft_check_id(element->id)) == FT_PARSE_DEFAULT ||
		id == FT_PARSE_LIGHT ||
		id == FT_PARSE_CAMERA ||
		id == FT_PARSE_AMBIENT_LIGHT ||
		id == FT_PARSE_RESOLUTION)
		return (0);
	get_truc_spec_color[FT_PARSE_CYLINDER - 4] = ft_get_cylinder_spec_color;
	get_truc_spec_color[FT_PARSE_TRIANGLE - 4] = ft_get_triangle_spec_color;
	get_truc_spec_color[FT_PARSE_SQUARE - 4] = ft_get_square_spec_color;
	get_truc_spec_color[FT_PARSE_PLANE - 4] = ft_get_plane_spec_color;
	get_truc_spec_color[FT_PARSE_SPHERE - 4] = ft_get_sphere_spec_color;
	get_truc_spec_color[FT_PARSE_CIRCLE - 4] = ft_get_circle_spec_color;
	get_truc_spec_color[FT_PARSE_ELLIPSOID - 4] = ft_get_ellipsoid_spec_color;
	return (get_truc_spec_color[id - 4](element->content));
}

#endif
