/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_geometric_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:24:15 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/23 22:44:40 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "ft_renderer.h"

int		ft_read_double(char **str, double *res, char *err, void *tfree)
{
	char *current;

	current = ft_substr(*str, 0, ft_segment_len(*str));
	if (!ft_check_double(current, res, 0))
	{
		ft_print_error(err, 0, 0);
		free(current);
		free(tfree);
		return (0);
	}
	free(current);
	*str += ft_segment_len(*str);
	ft_skip_separator(str, " \t");
	return (1);
}

void	ft_read_specular(char **str, unsigned int *color, double *shiny)
{
	if (!ft_read_double(str, shiny, "Error parsing : wrong specular coeff",
		NULL))
		*shiny = -1;
	if (!ft_read_color(str, color, NULL))
		*color = 0;
}
