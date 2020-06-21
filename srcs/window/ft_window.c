/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:14:00 by teyber            #+#    #+#             */
/*   Updated: 2020/06/20 21:00:50 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_window.h"
#include "debug.h"

static	int	hook_close(t_data *data)
{
	free(data->mode);
	mlx_destroy_image(data->mlx, data->img);
	ft_destroy_scene(data->scene);
	exit(0);
}

int			hook_keydown(int key_code, t_data *data)
{
	int		arrows;

	if (key_code == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		hook_close(data);
	}
	else if ((arrows = ft_identify_arrows(key_code)))
		ft_keydown_arrows(arrows, data);
	else if (key_code == KEY_W)
		data->mode->type = TYPE_MODE_CAMERAS;
	else if (key_code == KEY_Q)
		data->mode->type = TYPE_MODE_LIGHTS;
	else if (key_code == KEY_E)
		data->mode->type = TYPE_MODE_GEOMETRICALS;
	else if (key_code == KEY_F)
	{
		++data->mode->arrow;
		data->mode->arrow %= 3;
	}
	ft_print_selected(data);
	return (1);
}

int			hook_loop(t_data *data)
{
	ft_print_selected(data);
	return (1);
}

/*
** Pour le debug:
** mlx_loop_hook(data->mlx, hook_loop, data);
*/

void		ft_window(t_data *data)
{
	data->mode->arrow = 0;
	data->mode->type = TYPE_MODE_CAMERAS;
	mlx_do_key_autorepeatoff(data->mlx);
	mlx_hook(data->win, 17, 1L << 17, hook_close, data);
	mlx_hook(data->win, 2, 1L << 0, hook_keydown, data);
	ft_ray_tracing(data);
	mlx_loop(data->mlx);
}

void		ft_render(t_scene *scene, int file)
{
	t_data			data;
	t_resolution	*r;

	data.scene = scene;
	if (file)
	{
		data.target = file;
		ft_ray_tracing(&data);
		return ;
	}
	r = scene->resol;
	if (!(data.mlx = mlx_init()))
		return ;
	if (!(data.win = mlx_new_window(data.mlx, r->width, r->height, "miniRT")))
		return ;
	if (!(data.img = mlx_new_image(data.mlx, r->width, r->height)))
	{
		mlx_destroy_window(data.mlx, data.win);
		return ;
	}
	if (!(data.mode = (t_key_mode *)malloc(sizeof(t_key_mode))))
		return ;
	data.target = 0;
	ft_window(&data);
}
