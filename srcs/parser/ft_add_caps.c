/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_caps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 00:09:06 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/21 12:38:00 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "ft_maths.h"

static t_element	*ft_put_in_element(t_circle *circle)
{
	t_element	*element;

	if (!(element = (t_element *)malloc(sizeof(t_element))))
		return (NULL);
	element->id = ft_strdup("ci");
	element->content = circle;
	return (element);
}

static t_circle		*ft_create_circle(t_cylinder *cylinder, t_vector coord)
{
	t_circle	*circle;

	if (!(circle = (t_circle *)malloc(sizeof(t_circle))))
		return (NULL);
	circle->writable = 0;
	ft_memcpy(&circle->diameter, &cylinder->diameter, sizeof(double));
	ft_memcpy(circle->coord, coord, sizeof(t_vector));
	ft_memcpy(circle->normal, cylinder->orient, sizeof(t_vector));
	ft_memcpy(&circle->color, &cylinder->color, sizeof(int));
	return (circle);
}

void				ft_add_caps(t_scene *scene, t_cylinder *cylinder)
{
	t_circle	*cap1;
	t_circle	*cap2;
	t_vector	coord_c2;

	if (!cylinder->caps)
		return ;
	if (!(cap1 = ft_create_circle(cylinder, cylinder->coord)))
		return ;
	ft_vector_mult_lambda(coord_c2, cylinder->orient, cylinder->height);
	ft_vector_add(coord_c2, coord_c2, cap1->coord);
	if (!(cap2 = ft_create_circle(cylinder, coord_c2)))
	{
		free(cap1);
		return ;
	}
	cylinder->cap_shape[0] = cap1;
	cylinder->cap_shape[1] = cap2;
	ft_add_geometrical(scene, ft_put_in_element(cap1));
	ft_add_geometrical(scene, ft_put_in_element(cap2));
}
