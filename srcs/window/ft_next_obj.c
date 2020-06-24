/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:17:12 by rbourgea          #+#    #+#             */
/*   Updated: 2020/01/28 18:59:02 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_window.h"

void	ft_next_cam(t_data *data)
{
	t_list		*next;

	next = data->scene->cameras->next;
	if (next)
		data->scene->cameras = next;
}

void	ft_next_geo(t_data *data)
{
	t_list		*next;

	if (!data->scene->geometricals)
		return ;
	next = data->scene->geometricals->next;
	if (next)
		data->scene->geometricals = next;
}

void	ft_next_light(t_data *data)
{
	t_list		*next;

	if (!data->scene->lights)
		return ;
	next = data->scene->lights->next;
	if (next)
		data->scene->lights = next;
}
