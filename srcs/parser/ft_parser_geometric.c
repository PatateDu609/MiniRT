/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_geometric.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 09:35:34 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/23 19:48:45 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "ft_printf.h"
#include "ft_maths.h"

#ifndef BONUS

void		ft_parse_sphere(char *str, t_element *element)
{
	t_sphere	*result;

	element->content = NULL;
	if (!(result = (t_sphere *)malloc(sizeof(t_sphere))))
		ft_print_error("Malloc failed", 0, 1);
	if (!ft_read_coord(&str, result->origin, "Invalid coord for sphere",
			result))
		return ;
	if (!ft_read_double(&str, &result->diameter, "Invalid diameter", result))
		return ;
	if (!ft_read_color(&str, &result->color, result))
		return ;
	element->content = result;
}

#else

void		ft_parse_sphere(char *str, t_element *element)
{
	t_sphere	*result;

	element->content = NULL;
	if (!(result = (t_sphere *)malloc(sizeof(t_sphere))))
		ft_print_error("Malloc failed", 0, 1);
	if (!ft_read_coord(&str, result->origin, "Invalid coord for sphere",
			result))
		return ;
	if (!ft_read_double(&str, &result->diameter, "Invalid diameter", result))
		return ;
	if (!ft_read_color(&str, &result->color, result))
		return ;
	ft_read_specular(&str, &result->spec_color, &result->shiny);
	element->content = result;
}

#endif

void		ft_parse_square(char *str, t_element *element)
{
	t_square	*res;

	element->content = NULL;
	if (!(res = (t_square *)malloc(sizeof(t_square))))
		ft_print_error("Malloc failed", 0, 1);
	if (!ft_read_coord(&str, res->coord, "Invalid coord for square", res))
		return ;
	if (!ft_read_norm(&str, res->normal, "Invalid orientation for square", res))
		return ;
	if (!ft_read_double(&str, &res->size, "Invalid size for square", res))
		return ;
	if (!ft_read_color(&str, &res->color, res))
		return ;
	ft_vector_normalize(res->normal);
	res->first_pass = 1;
	element->content = res;
}

void		ft_parse_plane(char *str, t_element *element)
{
	t_plane		*res;

	element->content = NULL;
	if (!(res = (t_plane *)malloc(sizeof(t_plane))))
		ft_print_error("Malloc failed", 0, 1);
	if (!ft_read_coord(&str, res->coord, "Invalid coord for plane", res))
		return ;
	if (!ft_read_norm(&str, res->normal,
		"Invalid orientation for plane", res))
		return ;
	if (!ft_read_color(&str, &res->color, res))
		return ;
	ft_vector_normalize(res->normal);
	element->content = res;
}

void		ft_parse_cylinder(char *str, t_element *element)
{
	t_cylinder	*res;

	element->content = NULL;
	if (!(res = (t_cylinder *)malloc(sizeof(t_cylinder))))
		ft_print_error("Malloc failed", 0, 1);
	if (!ft_read_coord(&str, res->coord, "Invalid coord for cylinder", res))
		return ;
	if (!ft_read_norm(&str, res->orient, "Invalid orientation for cylinder",
		res))
		return ;
	if (!ft_read_color(&str, &res->color, res))
		return ;
	if (!ft_read_double(&str, &res->diameter, "Invalid diameter for cylinder",
		res))
		return ;
	if (!ft_read_double(&str, &res->height, "Invalid height for cylinder",
		res))
		return ;
	ft_skip_separator(&str, " \t");
	res->caps = !ft_strncmp("caps", str, max(ft_strlen(str), 4));
	ft_vector_normalize(res->orient);
	element->content = res;
}
