/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_geometric_other.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 23:24:08 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/21 12:42:18 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_parse_circle(char *str, t_element *element)
{
	t_circle	*res;

	element->content = NULL;
	if (!(res = (t_circle *)malloc(sizeof(t_circle))))
		ft_print_error("Malloc failed", 0, 1);
	if (!ft_read_coord(&str, res->coord, "Invalid coord for circle", res))
		return ;
	if (!ft_read_norm(&str, res->normal, "Invalid normal for circle",
		res))
		return ;
	if (!ft_read_color(&str, &res->color, res))
		return ;
	if (!ft_read_double(&str, &res->diameter, "Invalid diameter for circle",
		res))
		return ;
	element->content = res;
}

void	ft_parse_ellipsoid(char *str, t_element *element)
{
	t_ellipsoid		*res;
	int				i;

	element->content = NULL;
	if (!(res = (t_ellipsoid *)malloc(sizeof(t_ellipsoid))))
		return ;
	if (!ft_read_coord(&str, res->coord, "Invalid coord for ellipsoid", res))
		return ;
	i = 0;
	while (i < 3)
		if (!ft_read_double(&str, res->coeffs + i++,
			"Invalid coeff for ellipsoid", res))
			return ;
	if (!ft_read_color(&str, &res->color, res))
		return ;
	element->content = res;
}
