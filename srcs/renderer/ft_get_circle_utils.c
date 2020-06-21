/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_circle_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 21:03:38 by gboucett          #+#    #+#             */
/*   Updated: 2020/03/11 21:42:32 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_renderer.h"

unsigned int	ft_get_circle_color(void *circle)
{
	t_circle	*obj;

	obj = (t_circle *)circle;
	return (obj->color);
}

double			ft_get_circle_shiny(void *circle)
{
	t_circle	*obj;

	obj = (t_circle *)circle;
	return (obj->shiny);
}

unsigned int	ft_get_circle_spec_color(void *circle)
{
	t_circle	*obj;

	obj = (t_circle *)circle;
	return (obj->spec_color);
}
