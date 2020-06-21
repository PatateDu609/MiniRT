/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrows.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:16:53 by gboucett          #+#    #+#             */
/*   Updated: 2020/06/20 21:00:36 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_window.h"

static void	ft_select_object(int arrows, t_data *data)
{
	if (data->mode->type == TYPE_MODE_CAMERAS && arrows == 2)
		ft_next_cam(data);
	else if (data->mode->type == TYPE_MODE_CAMERAS && arrows == 4)
		ft_prev_cam(data);
	else if (data->mode->type == TYPE_MODE_LIGHTS && arrows == 2)
		ft_next_light(data);
	else if (data->mode->type == TYPE_MODE_LIGHTS && arrows == 4)
		ft_prev_light(data);
	else if (data->mode->type == TYPE_MODE_GEOMETRICALS && arrows == 2)
		ft_next_geo(data);
	else if (data->mode->type == TYPE_MODE_GEOMETRICALS && arrows == 4)
		ft_prev_geo(data);
}

static void	ft_alter_unique(int arrows, t_data *data)
{
	t_element *element;

	if (data->mode->type != TYPE_MODE_GEOMETRICALS)
		return ;
	element = (t_element *)data->scene->geometricals->content;
	if (arrows == 3 || arrows == 6)
		ft_modify_unique(element, arrows == 3, 1);
	else if (arrows == 1 || arrows == 5)
		ft_modify_unique(element, arrows == 1, -1);
}

static void	ft_move_coord(int arrows, t_data *data,
			void (*ft_modify_struct[7])(void *, int, double))
{
	if (arrows == 1 || arrows == 3)
		ft_move_xyz(data, MODE_COORD_Z, arrows == 1 ? -1 : 1, ft_modify_struct);
	else if (arrows == 2 || arrows == 4)
		ft_move_xyz(data, MODE_COORD_X, arrows == 4 ? -1 : 1, ft_modify_struct);
	else if (arrows == 5 || arrows == 6)
		ft_move_xyz(data, MODE_COORD_Y, arrows == 5 ? -1 : 1, ft_modify_struct);
}

static void	ft_alter_orientation(int arrows, t_data *data,
			void (*ft_modify_struct[7])(void *, int, double))
{
	if (arrows == 1 || arrows == 3)
		ft_move_xyz(data, MODE_ORIENTATION_Z,
			arrows == 1 ? -1 : 1, ft_modify_struct);
	else if (arrows == 2 || arrows == 4)
		ft_move_xyz(data, MODE_ORIENTATION_X,
			arrows == 4 ? -1 : 1, ft_modify_struct);
	else if (arrows == 5 || arrows == 6)
		ft_move_xyz(data, MODE_ORIENTATION_Y,
			arrows == 5 ? -1 : 1, ft_modify_struct);
}

/*
** ft_redraw_window(data);
*/

void		ft_keydown_arrows(int arrows, t_data *data)
{
	void (*ft_modify_struct[9])(void *, int, double);

	ft_modify_struct[FT_PARSE_LIGHT] = ft_modify_light;
	ft_modify_struct[FT_PARSE_CAMERA] = ft_modify_camera;
	ft_modify_struct[FT_PARSE_CYLINDER] = ft_modify_cylinder;
	ft_modify_struct[FT_PARSE_PLANE] = ft_modify_plane;
	ft_modify_struct[FT_PARSE_SQUARE] = ft_modify_square;
	ft_modify_struct[FT_PARSE_SPHERE] = ft_modify_sphere;
	if (data->mode->arrow == 0 && (arrows == 2 || arrows == 4))
		ft_select_object(arrows, data);
	else if (data->mode->arrow == 0 && (arrows % 2 == 1 || arrows == 6))
		ft_alter_unique(arrows, data);
	else if (data->mode->arrow == 1)
		ft_move_coord(arrows, data, ft_modify_struct);
	else
		ft_alter_orientation(arrows, data, ft_modify_struct);
	ft_ray_tracing(data);
}
