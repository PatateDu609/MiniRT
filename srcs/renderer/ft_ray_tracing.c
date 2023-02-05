/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_tracing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:54:12 by teyber            #+#    #+#             */
/*   Updated: 2020/06/23 22:58:06 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_renderer.h"
#include "debug.h"

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
		if (!(data->img_addr = (unsigned int *)calloc(s[0] * s[1], 4)))
			return ;
		ft_draw(data, s[0], s[1]);
		if (data->target == 1)
			ft_save(data->img_addr, s[0], s[1]);
		else if (data->target == 2)
			ft_save_png(data->img_addr, s[0], s[1]);
		free(data->img_addr);
	}
}
