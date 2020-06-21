/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_triangle_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:50:45 by gboucett          #+#    #+#             */
/*   Updated: 2020/03/11 21:44:27 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_renderer.h"

unsigned int	ft_get_triangle_color(void *triangle)
{
	t_triangle		*obj;

	obj = (t_triangle *)triangle;
	return (obj->color);
}

double			ft_get_triangle_shiny(void *triangle)
{
	t_triangle		*obj;

	obj = (t_triangle *)triangle;
	return (obj->shiny);
}

unsigned int	ft_get_triangle_spec_color(void *triangle)
{
	t_triangle	*obj;

	obj = (t_triangle *)triangle;
	return (obj->spec_color);
}
