/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prev_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:20:57 by rbourgea          #+#    #+#             */
/*   Updated: 2020/01/28 18:59:15 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_window.h"

void	ft_prev_cam(t_data *data)
{
	t_list		*prev;

	prev = data->scene->cameras->previous;
	if (prev)
		data->scene->cameras = prev;
}

void	ft_prev_geo(t_data *data)
{
	t_list		*prev;

	if (!data->scene->geometricals)
		return ;
	prev = data->scene->geometricals->previous;
	if (prev)
		data->scene->geometricals = prev;
}

void	ft_prev_light(t_data *data)
{
	t_list		*prev;

	if (!data->scene->lights)
		return ;
	prev = data->scene->lights->previous;
	if (prev)
		data->scene->lights = prev;
}
