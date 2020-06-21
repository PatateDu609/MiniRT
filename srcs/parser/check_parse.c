/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:56:30 by gboucett          #+#    #+#             */
/*   Updated: 2020/06/21 22:47:05 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int			ft_check_id_2(char *identifier, size_t len)
{
	if (len == 0 || len > 2)
		return (FT_PARSE_DEFAULT);
	if (len == 1 && !ft_strncmp(identifier, "R", 1))
		return (FT_PARSE_RESOLUTION);
	else if (len == 1 && !ft_strncmp(identifier, "A", 1))
		return (FT_PARSE_AMBIENT_LIGHT);
	else if (len == 1 && !ft_strncmp(identifier, "F", 1))
		return (FT_PARSE_FILTER);
	else if (len == 1 && !ft_strncmp(identifier, "l", 1))
		return (FT_PARSE_LIGHT);
	else if (len == 1 && !ft_strncmp(identifier, "c", 1))
		return (FT_PARSE_CAMERA);
	else if (!ft_strncmp(identifier, "sp", 2))
		return (FT_PARSE_SPHERE);
	else if (!ft_strncmp(identifier, "sq", 2))
		return (FT_PARSE_SQUARE);
	else if (!ft_strncmp(identifier, "pl", 2))
		return (FT_PARSE_PLANE);
	else if (!ft_strncmp(identifier, "cy", 2))
		return (FT_PARSE_CYLINDER);
	else if (!ft_strncmp(identifier, "tr", 2))
		return (FT_PARSE_TRIANGLE);
	else
		return (-1);
}

int			ft_check_id(char *identifier)
{
	size_t	len;
	int		check;

	len = ft_strlen((const char*)identifier);
	check = ft_check_id_2(identifier, len);
	if (!ft_strncmp(identifier, "ci", 2))
		return (FT_PARSE_CIRCLE);
	else if (!ft_strncmp(identifier, "el", 2))
		return (FT_PARSE_ELLIPSOID);
	else if (check == -1)
		return (FT_PARSE_DEFAULT);
	else
		return (check);
}

int			ft_check_color(char *str, unsigned int *color)
{
	int		red;
	int		blue;
	int		green;

	if (!ft_count_color_fields(str))
		return (0);
	red = ft_atoi(str);
	ft_skip_separator(&str, "0123456789 \t");
	ft_skip_separator(&str, ",");
	green = ft_atoi(str);
	ft_skip_separator(&str, "0123456789 \t");
	ft_skip_separator(&str, ",");
	blue = ft_atoi(str);
	*color = red << 16 | green << 8 | blue;
	return (0 <= red && red <= 255
			&& 0 <= green && green <= 255
			&& 0 <= blue && blue <= 255);
}

int			ft_check_double(char *str, double *number, int ratio)
{
	if (!ft_special_strchr(str, "0123456789\n\t\v\f\r ."))
		return (0);
	*number = ft_strtof(str);
	if (!ratio)
		return (1);
	return (0. <= *number && *number <= 1.);
}

int			ft_check_vector(char *str, int interval, t_vector vector)
{
	char	*current;
	int		i;

	i = 0;
	while (i < 3)
	{
		current = ft_substr(str, 0, ft_strchr(str, ',') - str);
		vector[i] = ft_strtof(current);
		ft_skip_separator(&str, "0123456789. -\t");
		ft_skip_separator(&str, ",");
		free(current);
		i++;
	}
	if (!interval)
		return (1);
	return (-1. <= vector[0] && vector[0] <= 1.
			&& -1. <= vector[1] && vector[1] <= 1.
			&& -1. <= vector[2] && vector[2] <= 1.);
}
