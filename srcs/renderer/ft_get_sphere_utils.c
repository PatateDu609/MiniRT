/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sphere_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:50:27 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/18 13:04:40 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_renderer.h"

unsigned	int	ft_get_sphere_color(void *sphere)
{
	t_sphere		*obj;

	obj = (t_sphere *)sphere;
	return (obj->color);
}

double			ft_get_sphere_shiny(void *sphere)
{
	t_sphere		*obj;

	obj = (t_sphere *)sphere;
	return (obj->shiny);
}

unsigned int	ft_get_sphere_spec_color(void *sphere)
{
	t_sphere	*obj;

	obj = (t_sphere *)sphere;
	return (obj->spec_color);
}
