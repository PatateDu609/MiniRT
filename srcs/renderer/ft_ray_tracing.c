/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_tracing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:54:12 by teyber            #+#    #+#             */
/*   Updated: 2020/06/22 15:24:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_renderer.h"
#include "debug.h"

unsigned int	ft_filter(int filter, unsigned int color)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	t_vector		result;

	if (filter == NO_FILTER)
		return (color);
	ft_hexa_to_rgb(color, &r, &g, &b);
	if (filter == FILTER_GRAYSCALE)
	{
		result[0] = r * .2126 + g * .7152 + b * .0722;
		result[1] = r * .2126 + g * .7152 + b * .0722;
		result[2] = r * .2126 + g * .7152 + b * .0722;
	}
	else if (filter == FILTER_SEPIA)
	{
		result[0] = r * .393 + g * .769 + b * .189;
		result[1] = r * .349 + g * .686 + b * .168;
		result[2] = r * .272 + g * .534 + b * .131;
	}
	else
		return (color);
	return (ft_rgb_to_hexa(min(255, result[0]), min(255, result[1]), min(255,
		result[2])));
}

static void		ft_draw_pixel(t_data *data, int pixel_coord[2], int w, int h)
{
	unsigned int	*p;
	t_ray			*ray;
	t_intersect		inter;
	t_vector		pos_cam;

	p = data->img_addr;
	if (data->target)
		p += w * (h - pixel_coord[1] - 1) + pixel_coord[0];
	else
		p += w * pixel_coord[1] + pixel_coord[0];
	*p = DEFAULT_COLOR;
	if (!(ray = ft_cast_cam_ray(data->scene, pixel_coord)))
		return ;
	if (ft_intersect(data->scene, ray, &inter))
	{
		if (ft_check_id(inter.element->id) != FT_PARSE_CYLINDER)
		{
			ft_vector_sub(pos_cam, ray->origin, inter.pos);
			ft_vector_mult_lambda(inter.normal, inter.normal,
				sign(ft_vector_dot(inter.normal, pos_cam)));
		}
		*p = ft_filter(data->scene->filter, ft_color(data->scene, &inter));
	}
	free(ray);
}

static void		ft_draw(t_data *data, int width, int height)
{
	int				pixel_coord[2];

	pixel_coord[1] = 0;
	while (pixel_coord[1] < height)
	{
		pixel_coord[0] = 0;
		while (pixel_coord[0] < width)
		{
			ft_draw_pixel(data, pixel_coord, width, height);
			pixel_coord[0]++;
		}
		pixel_coord[1]++;
	}
}

/*
** #define THREAD_COUNT 16
**
** void multi_thread(t_data *data)
** {
** 	int i;
** 	pthread_t thr[THREAD_COUNT];
** 	t_thread thread[THREAD_COUNT];
**
** 	i = 0;
** 	while (i < THREAD_COUNT)
** 	{
** 		thread[i].cur_thr = i;
** 		ft_memcpy(&thread[i].scene, data, sizeof(t_data));
** 		thread[i].scene.tr = i;
** 		pthread_create(&thr[i], NULL, (void *)ft_ray_tracing, &thread[i]);
** 		i++;
** 	}
** 	i = 0;
** 	while (i < THREAD_COUNT)
** 	{
** 		pthread_join(thr[i], NULL);
** 		i++;
** 	}
** }
**
** void ft_redraw_window(t_data *data)
** {
** 	// setup_rt(data);
** 	multi_thread(data);
** 	// mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
** }
*/

void			ft_set_size(t_data *data, int *width, int *height)
{
	int screen_size[2];

	mlx_get_screen_size(data->mlx, screen_size, screen_size + 1);
	if (*width > screen_size[0])
		*width = screen_size[0];
	if (*height > screen_size[1])
		*height = screen_size[1];
}

void			ft_ray_tracing(t_data *data)
{
	int		s[2];
	int		trash;

	s[0] = data->scene->resol->width;
	s[1] = data->scene->resol->height;
	if (!data->target)
	{
		if (!(data->img_addr = (unsigned int *)mlx_get_data_addr(data->img,
			&trash, &trash, &trash)))
			return ;
		ft_draw(data, s[0], s[1]);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else
	{
		if (!(data->img_addr = (unsigned int *)ft_calloc(s[0] * s[1], 4)))
			return ;
		ft_draw(data, s[0], s[1]);
		if (data->target == 1)
			ft_save(data->img_addr, s[0], s[1]);
		else if (data->target == 2)
			ft_save_png(data->img_addr, s[0], s[1]);
		free(data->img_addr);
	}
}
