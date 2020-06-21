/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_structs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:02:52 by gboucett          #+#    #+#             */
/*   Updated: 2020/06/19 22:11:45 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void			ft_print_vector(t_vector vector)
{
	printf("x = %lf, y = %lf, z = %lf\n", vector[0], vector[1], vector[2]);
}

char			*ft_translate_id_2(char *id)
{
	if (!ft_strncmp(id, "sq", 2))
		return ("Square");
	else if (!ft_strncmp(id, "pl", 2))
		return ("Plane");
	else if (!ft_strncmp(id, "cy", 2))
		return ("Cylinder");
	else if (!ft_strncmp(id, "tr", 2))
		return ("Triangle");
	else
		return ("Invalid identifier");
}

char			*ft_translate_id(char *id)
{
	size_t len;

	len = ft_strlen(id);
	if (len == 1 && !ft_strncmp(id, "R", 1))
		return ("Resolution");
	else if (len == 1 && !ft_strncmp(id, "A", 1))
		return ("Ambient light");
	else if (len == 1 && !ft_strncmp(id, "l", 1))
		return ("Light");
	else if (len == 1 && !ft_strncmp(id, "c", 1))
		return ("Camera");
	else if (!ft_strncmp(id, "sp", 2))
		return ("Sphere");
	else if (!ft_strncmp(id, "sq", 2))
		return ("Square");
	else
		return (ft_translate_id_2(id));
}

void			ft_print_plane(t_element *element)
{
	t_plane *plane;

	if (!element->content)
	{
		printf("Invalid plane\n");
		return ;
	}
	plane = (t_plane *)element->content;
	printf("Coordinates of a point of the plane : ");
	ft_print_vector(plane->coord);
	printf("Orientation : ");
	ft_print_vector(plane->normal);
	ft_printf("Color : %X\n", plane->color);
}

void			ft_print_element(t_element *element)
{
	void (*ft_print[9])(t_element *);

	if (!element)
	{
		ft_printf("Invalid element !\n");
		return ;
	}
	ft_printf("type : %s at %p\n", ft_translate_id(element->id), element);
	ft_print[FT_PARSE_RESOLUTION] = ft_print_resolution;
	ft_print[FT_PARSE_AMBIENT_LIGHT] = ft_print_ambient_light;
	ft_print[FT_PARSE_LIGHT] = ft_print_light;
	ft_print[FT_PARSE_CAMERA] = ft_print_camera;
	ft_print[FT_PARSE_SPHERE] = ft_print_sphere;
	ft_print[FT_PARSE_SQUARE] = ft_print_square;
	ft_print[FT_PARSE_PLANE] = ft_print_plane;
	ft_print[FT_PARSE_CYLINDER] = ft_print_cylinder;
	ft_print[FT_PARSE_TRIANGLE] = ft_print_triangle;
	ft_print[ft_check_id(element->id)](element);
}
