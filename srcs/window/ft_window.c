/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:14:00 by teyber            #+#    #+#             */
/*   Updated: 2020/06/23 23:35:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_window.h"
#include "debug.h"

void		ft_render(t_scene *scene, int file)
{
	t_data			data;
	t_resolution	*r;

	data.target = file + 1;
	data.scene = scene;
	ft_ray_tracing(&data);
	return ;
}
