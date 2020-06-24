/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_png.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 21:42:24 by rbourgea          #+#    #+#             */
/*   Updated: 2020/03/12 22:36:09 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_renderer.h"
#include "libattopng.h"

void	ft_save_png(unsigned int *data, int width, int height)
{
	libattopng_t	*png;
	int				x;
	int				y;
	unsigned int	color;
	unsigned int	rgb[3];

	png = libattopng_new(width, height, PNG_RGBA);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			ft_hexa_to_rgb(data[width * (height - y - 1) + x], rgb, rgb + 1,
				rgb + 2);
			color = rgb[0] | rgb[1] << 8 | rgb[2] << 16 | 255 << 24;
			libattopng_set_pixel(png, x, y, color);
			x++;
		}
		y++;
	}
	libattopng_save(png, "minirt.png");
	libattopng_destroy(png);
}
