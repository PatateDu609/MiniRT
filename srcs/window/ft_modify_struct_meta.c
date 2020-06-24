/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_struct_meta.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 14:59:05 by rbourgea          #+#    #+#             */
/*   Updated: 2020/02/01 20:06:30 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_window.h"

void				ft_modify_camera(void *element, int mode, double delta)
{
	t_camera *camera;

	camera = (t_camera *)element;
	if (mode == MODE_COORD_X)
		camera->view[0] += delta;
	else if (mode == MODE_COORD_Y)
		camera->view[1] += delta;
	else if (mode == MODE_COORD_Z)
		camera->view[2] += delta;
	else if (mode == MODE_ORIENTATION_X)
		camera->orientation[0] += delta;
	else if (mode == MODE_ORIENTATION_Y)
		camera->orientation[1] += delta;
	else if (mode == MODE_ORIENTATION_Z)
		camera->orientation[2] += delta;
}

void				ft_modify_light(void *element, int mode, double delta)
{
	t_light *light;

	light = (t_light *)element;
	if (mode == MODE_COORD_X)
		light->coord[0] += delta;
	else if (mode == MODE_COORD_Y)
		light->coord[1] += delta;
	else if (mode == MODE_COORD_Z)
		light->coord[2] += delta;
}
