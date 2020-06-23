/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 22:56:54 by gboucett          #+#    #+#             */
/*   Updated: 2020/06/23 22:58:51 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_renderer.h"

#ifndef BONUS

void		ft_draw_pixel(t_data *data, int pixel_coord[2], int w, int h)
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
		*p = ft_color(data->scene, &inter);
	}
	free(ray);
}

#else

void		ft_draw_pixel(t_data *data, int pixel_coord[2], int w, int h)
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

#endif
