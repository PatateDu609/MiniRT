/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_selected.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:00:41 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/17 13:21:23 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include <stdio.h>

void	ft_print_selected_2(t_data *data)
{
	if (data->mode->type == TYPE_MODE_GEOMETRICALS)
	{
		printf("geometricals\n");
		if (data->scene->geometricals)
			ft_print_element((t_element *)data->scene->geometricals->content);
	}
	else if (data->mode->type == TYPE_MODE_LIGHTS)
	{
		printf("lights\n");
		if (data->scene->lights)
			ft_print_light((t_element *)data->scene->lights->content);
	}
}

void	ft_print_selected(t_data *data)
{
	printf("\n-------------------------------------------------------------\n");
	if (data->mode->arrow == 0)
		printf("Selection object mode\n");
	else if (data->mode->arrow == 1)
		printf("Coordinates mode\n");
	else if (data->mode->arrow == 2)
		printf("Orientation mode\n");
	printf("Mode : ");
	if (data->mode->type == TYPE_MODE_CAMERAS)
	{
		printf("cameras\n");
		ft_print_camera((t_element *)data->scene->cameras->content);
	}
	ft_print_selected_2(data);
	printf("\n-------------------------------------------------------------\n");
}
