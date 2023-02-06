/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_tracing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:54:12 by teyber            #+#    #+#             */
/*   Updated: 2023/02/06 10:29:35 by gboucett         ###   ########.fr       */
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

void			ft_ray_tracing(t_data *data)
{
	int		s[2];

	s[0] = data->scene->resol->width;
	s[1] = data->scene->resol->height;
	if (!(data->img_addr = (unsigned int *)calloc(s[0] * s[1], 4)))
		return ;
	ft_draw(data, s[0], s[1]);
	if (data->target == 1)
		ft_save(data->img_addr, s[0], s[1]);
	else if (data->target == 2)
		ft_save_png(data->img_addr, s[0], s[1]);
	free(data->img_addr);
}
