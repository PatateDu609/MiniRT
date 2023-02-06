/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:14:00 by teyber            #+#    #+#             */
/*   Updated: 2023/02/06 10:29:15 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_window.h"
#include "debug.h"

void		ft_render(t_scene *scene, int file)
{
	t_data			data;

	data.target = file + 1;
	data.scene = scene;
	ft_ray_tracing(&data);
	return ;
}
