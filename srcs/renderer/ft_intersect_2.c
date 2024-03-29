/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:04:45 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/23 23:05:20 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_renderer.h"
#include "debug.h"

void			*ft_get_element(t_list *list)
{
	t_element	*element;

	element = (t_element *)list->content;
	return (element->content);
}

unsigned int	ft_add_color(unsigned int ca, unsigned int cb)
{
	unsigned int		cargb[3];
	unsigned int		cbrgb[3];
	unsigned int		result[3];

	ft_hexa_to_rgb(ca, cargb, cargb + 1, cargb + 2);
	ft_hexa_to_rgb(cb, cbrgb, cbrgb + 1, cbrgb + 2);
	result[0] = min(255, max(0, cargb[0] + cbrgb[0]));
	result[1] = min(255, max(0, cargb[1] + cbrgb[1]));
	result[2] = min(255, max(0, cargb[2] + cbrgb[2]));
	return (ft_rgb_to_hexa(result[0], result[1], result[2]));
}

unsigned int	ft_ambient(t_light *ambient, t_element *element)
{
	unsigned	int r;
	unsigned	int g;
	unsigned	int b;
	t_vector		lambda;

	ft_hexa_to_rgb(ambient->color, &r, &g, &b);
	lambda[0] = ambient->ratio * (r / 255.);
	lambda[1] = ambient->ratio * (g / 255.);
	lambda[2] = ambient->ratio * (b / 255.);
	return (ft_hex_mult(ft_get_object_color(element), lambda));
}

unsigned int	ft_shadow(t_scene *scene, t_light *light, t_intersect *inter)
{
	t_ray		ray;
	t_intersect	linter;
	int			has_inter_light;
	t_vector	l_p;

	ft_vector_mult_lambda(ray.origin, inter->normal, 0.0001);
	ft_vector_add(ray.origin, ray.origin, inter->pos);
	ft_vector_sub(l_p, light->coord, inter->pos);
	memcpy(ray.direct, l_p, sizeof(t_vector));
	ft_vector_normalize(ray.direct);
	has_inter_light = ft_intersect(scene, &ray, &linter);
	return (!(has_inter_light && linter.param * linter.param <
		ft_vector_norm2(l_p)));
}
