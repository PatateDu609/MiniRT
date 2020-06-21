/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ellipsoid_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:50:30 by gboucett          #+#    #+#             */
/*   Updated: 2020/03/11 21:45:29 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_renderer.h"

unsigned int	ft_get_ellipsoid_color(void *ellipsoid)
{
	t_ellipsoid		*obj;

	obj = (t_ellipsoid *)ellipsoid;
	return (obj->color);
}

double			ft_get_ellipsoid_shiny(void *ellipsoid)
{
	t_ellipsoid		*obj;

	obj = (t_ellipsoid *)ellipsoid;
	return (obj->shiny);
}

unsigned int	ft_get_ellipsoid_spec_color(void *ellipsoid)
{
	t_ellipsoid	*obj;

	obj = (t_ellipsoid *)ellipsoid;
	return (obj->spec_color);
}
