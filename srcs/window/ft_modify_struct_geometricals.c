/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_struct_geometricals.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 14:59:03 by gboucett          #+#    #+#             */
/*   Updated: 2020/02/20 17:48:13 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_window.h"

void	ft_modify_sphere(void *element, int mode, double delta)
{
	t_sphere *sphere;

	sphere = (t_sphere *)element;
	if (mode == MODE_COORD_X)
		sphere->origin[0] += delta;
	else if (mode == MODE_COORD_Y)
		sphere->origin[1] += delta;
	else if (mode == MODE_COORD_Z)
		sphere->origin[2] += delta;
}

void	ft_modify_plane(void *element, int mode, double delta)
{
	t_plane *plane;

	plane = (t_plane *)element;
	if (mode == MODE_COORD_X)
		plane->coord[0] += delta;
	else if (mode == MODE_COORD_Y)
		plane->coord[1] += delta;
	else if (mode == MODE_COORD_Z)
		plane->coord[2] += delta;
	else if (mode == MODE_ORIENTATION_X)
		plane->normal[0] += delta;
	else if (mode == MODE_ORIENTATION_Y)
		plane->normal[1] += delta;
	else if (mode == MODE_ORIENTATION_Z)
		plane->normal[2] += delta;
}

void	ft_modify_square(void *element, int mode, double delta)
{
	t_square *square;

	square = (t_square *)element;
	if (mode == MODE_COORD_X)
		square->coord[0] += delta;
	else if (mode == MODE_COORD_Y)
		square->coord[1] += delta;
	else if (mode == MODE_COORD_Z)
		square->coord[2] += delta;
	else if (mode == MODE_ORIENTATION_X)
		square->normal[0] += delta;
	else if (mode == MODE_ORIENTATION_Y)
		square->normal[1] += delta;
	else if (mode == MODE_ORIENTATION_Z)
		square->normal[2] += delta;
}

void	ft_modify_cylinder(void *element, int mode, double delta)
{
	t_cylinder *cylinder;

	cylinder = (t_cylinder *)element;
	if (mode == MODE_COORD_X)
		cylinder->coord[0] += delta;
	else if (mode == MODE_COORD_Y)
		cylinder->coord[1] += delta;
	else if (mode == MODE_COORD_Z)
		cylinder->coord[2] += delta;
	else if (mode == MODE_ORIENTATION_X)
		cylinder->orient[0] += delta;
	else if (mode == MODE_ORIENTATION_Y)
		cylinder->orient[1] += delta;
	else if (mode == MODE_ORIENTATION_Z)
		cylinder->orient[2] += delta;
}
