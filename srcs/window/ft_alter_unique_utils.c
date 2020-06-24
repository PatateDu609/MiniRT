/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alter_unique_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:36:49 by rbourgea          #+#    #+#             */
/*   Updated: 2020/02/01 17:21:24 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_window.h"

static void		ft_modifyu_sphere(t_sphere *sphere, int coeff)
{
	if (sphere->diameter + coeff >= 0)
		sphere->diameter += coeff;
}

static void		ft_modifyu_cylinder(t_cylinder *cylinder, int mode, int coeff)
{
	if (mode && (cylinder->height + coeff >= 0))
		cylinder->height += coeff;
	else if (!mode && (cylinder->diameter + coeff >= 0))
		cylinder->diameter += coeff;
}

static void		ft_modifyu_square(t_square *square, int coeff)
{
	if (square->size + coeff >= 0)
		square->size += coeff;
}

void			ft_modify_unique(t_element *element, int mode, int coeff)
{
	int id;

	if ((id = ft_check_id(element->id)) == FT_PARSE_SPHERE)
		ft_modifyu_sphere(element->content, coeff);
	else if (id == FT_PARSE_SQUARE)
		ft_modifyu_square(element->content, coeff);
	else if (id == FT_PARSE_CYLINDER)
		ft_modifyu_cylinder(element->content, mode, coeff);
}
