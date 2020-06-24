/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_structs_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:02:52 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/19 22:11:23 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

static void		f(void *content)
{
	ft_print_element((t_element*)content);
	ft_printf("\n\n");
}

void			ft_print_scene_2(t_scene *scene, t_element ambient)
{
	ft_printf("\nLights :\n");
	ft_print_ambient_light(&ambient);
	ft_printf("\n\n");
	ft_lstiter(scene->lights, f);
	ft_printf("Cameras :\n");
	ft_printf("\nThere is %d cameras in the scene\n", scene->nb_cameras);
	ft_lstiter(scene->cameras, f);
	ft_printf("Geometricals :\n");
	ft_lstiter(scene->geometricals, f);
}

void			ft_print_scene(t_scene *scene)
{
	t_element resol;
	t_element ambient;

	if (!scene)
	{
		ft_printf("Invalid scene ! \n");
		return ;
	}
	ft_printf("Print scene at %p :\n", scene);
	resol.content = scene->resol;
	ambient.content = scene->ambient;
	ft_printf("\nResolution :\n");
	ft_print_resolution(&resol);
	ft_print_scene_2(scene, ambient);
}

void			ft_print_triangle(t_element *element)
{
	t_triangle	*triangle;
	int			i;

	triangle = (t_triangle *)element->content;
	if (!element->content)
	{
		printf("Invalid triangle\n");
		return ;
	}
	i = 0;
	while (i++ < 3)
	{
		printf("Coordinates of point no %d : ", i);
		ft_print_vector(triangle->coord[i - 1]);
	}
	ft_printf("Color : %X\n", triangle->color);
}

void			ft_print_cylinder(t_element *element)
{
	t_cylinder	*cylinder;

	if (!element->content)
	{
		printf("Invalid cylinder\n");
		return ;
	}
	cylinder = (t_cylinder *)element->content;
	printf("Coordinates of the center of the bottom base of the cylinder : ");
	ft_print_vector(cylinder->coord);
	printf("Orientation : ");
	ft_print_vector(cylinder->orient);
	printf("Height = %lf\n", cylinder->height);
	printf("Diameter = %lf\n", cylinder->diameter);
	ft_printf("Color : %X\n", cylinder->color);
}
