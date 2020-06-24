/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_structs_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:02:52 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/19 22:13:01 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	ft_print_square(t_element *element)
{
	t_square *square;

	if (!element->content)
	{
		printf("Invalid square\n");
		return ;
	}
	square = (t_square *)element->content;
	printf("Coordinates of a summit of the square : ");
	ft_print_vector(square->coord);
	printf("Orientation : ");
	ft_print_vector(square->normal);
	printf("Size = %lf\n", square->size);
	ft_printf("Color : %X\n", square->color);
}

void	ft_print_sphere(t_element *element)
{
	t_sphere *sphere;

	if (!element->content)
	{
		printf("Invalid sphere\n");
		return ;
	}
	sphere = (t_sphere *)element->content;
	printf("Coordinates of the center : ");
	ft_print_vector(sphere->origin);
	printf("Diameter : %lf\n", sphere->diameter);
	ft_printf("Color : %X\n", sphere->color);
}

void	ft_print_camera(t_element *element)
{
	t_camera *camera;

	if (!element->content)
	{
		printf("Invalid camera\n");
		return ;
	}
	camera = (t_camera *)element->content;
	printf("coordinates of the viewpoint : ");
	ft_print_vector(camera->view);
	printf("fov : %lf\n", camera->fov);
	printf("orientation : ");
	ft_print_vector(camera->orientation);
}

void	ft_print_light(t_element *element)
{
	t_light *light;

	if (!element->content)
	{
		printf("Invalid light\n");
		return ;
	}
	light = (t_light *)element->content;
	printf("Is it ambient ? %s\n", light->ambient ? "yes" : "no");
	printf("Ratio = %lf\n", light->ratio);
	if (!light->ambient)
	{
		printf("Coord : ");
		ft_print_vector(light->coord);
	}
	ft_printf("Color : %X\n", light->color);
}

void	ft_print_ambient_light(t_element *element)
{
	ft_print_light(element);
}
