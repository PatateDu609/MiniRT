/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_square_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:50:30 by gboucett          #+#    #+#             */
/*   Updated: 2020/03/11 21:44:04 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_renderer.h"

unsigned int	ft_get_square_color(void *square)
{
	t_square		*obj;

	obj = (t_square *)square;
	return (obj->color);
}

double			ft_get_square_shiny(void *square)
{
	t_square		*obj;

	obj = (t_square *)square;
	return (obj->shiny);
}

unsigned int	ft_get_square_spec_color(void *square)
{
	t_square	*obj;

	obj = (t_square *)square;
	return (obj->spec_color);
}
