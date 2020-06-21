/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cylinder_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:50:21 by gboucett          #+#    #+#             */
/*   Updated: 2020/03/11 21:42:57 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_renderer.h"

unsigned int	ft_get_cylinder_color(void *cylinder)
{
	t_cylinder		*obj;

	obj = (t_cylinder *)cylinder;
	return (obj->color);
}

double			ft_get_cylinder_shiny(void *cylinder)
{
	t_cylinder		*obj;

	obj = (t_cylinder *)cylinder;
	return (obj->shiny);
}

unsigned int	ft_get_cylinder_spec_color(void *cylinder)
{
	t_cylinder	*obj;

	obj = (t_cylinder *)cylinder;
	return (obj->spec_color);
}
