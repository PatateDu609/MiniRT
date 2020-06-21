/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_plane_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:50:25 by gboucett          #+#    #+#             */
/*   Updated: 2020/06/18 19:10:54 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_renderer.h"

unsigned int	ft_get_plane_color(void *plane)
{
	t_plane *obj;

	obj = (t_plane*)plane;
	return (obj->color);
}

double			ft_get_plane_shiny(void *plane)
{
	t_plane	*obj;

	obj = (t_plane*)plane;
	return (obj->shiny);
}

unsigned int	ft_get_plane_spec_color(void *plane)
{
	t_plane	*obj;

	obj = (t_plane*)plane;
	return (obj->spec_color);
}
