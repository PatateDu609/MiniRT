/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_geometric_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 09:35:34 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/23 19:48:37 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "ft_maths.h"

void		ft_parse_triangle(char *str, t_element *element)
{
	t_triangle	*result;
	int			i;

	element->content = NULL;
	if (!(result = (t_triangle *)malloc(sizeof(t_triangle))))
		ft_print_error("Malloc failed", 0, 1);
	i = 0;
	while (i++ < 3)
		if (!ft_read_coord(&str, result->coord[i - 1],
			"Invalid coord for triangle", result))
			return ;
	if (!ft_read_color(&str, &result->color, result))
		return ;
	element->content = result;
}
