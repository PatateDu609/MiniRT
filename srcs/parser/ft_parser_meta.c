/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_meta.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 08:19:56 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/21 12:42:40 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "ft_printf.h"

void		ft_parse_resolution(char *str, t_element *element)
{
	t_resolution *result;

	element->content = NULL;
	if (!(result = (t_resolution *)malloc(sizeof(t_resolution))))
		ft_print_error("Malloc failed", 0, 1);
	result->width = ft_atoi(str);
	str += ft_segment_len(str);
	ft_skip_separator(&str, " \t");
	if (!*str)
		ft_print_error("Two integers needed for Resolution type", 0, 1);
	result->height = ft_atoi(str);
	element->content = result;
}

void		ft_parse_ambient_light(char *str, t_element *element)
{
	t_light		*result;

	element->content = NULL;
	if (!(result = (t_light *)malloc(sizeof(t_light))))
		ft_print_error("Malloc failed", 0, 1);
	result->ambient = 1;
	if (!ft_read_ratio(&str, &result->ratio, result))
		return ;
	if (!ft_read_color(&str, &result->color, result))
		return ;
	element->content = result;
}

void		ft_parse_filter(char *str, t_element *element)
{
	int		*result;
	char	*res;

	element->content = NULL;
	if (!(result = (int *)malloc(sizeof(int))))
		return ;
	if (!(res = ft_strtrim(str, "\t ")))
		return ;
	*result = NO_FILTER;
	if (!ft_strncmp(res, "none", ft_strlen(res) < 4 ? 4 : ft_strlen(res)))
		*result = NO_FILTER;
	if (!ft_strncmp(res, "grayscale", ft_strlen(res) < 9 ? 9 : ft_strlen(res)))
		*result = FILTER_GRAYSCALE;
	if (!ft_strncmp(res, "sepia", ft_strlen(res) < 5 ? 5 : ft_strlen(res)))
		*result = FILTER_SEPIA;
	free(res);
	element->content = result;
}

void		ft_parse_light(char *str, t_element *element)
{
	t_light		*result;

	element->content = NULL;
	if (!(result = (t_light *)malloc(sizeof(t_light))))
		ft_print_error("Malloc failed", 0, 1);
	result->ambient = 0;
	if (!ft_read_coord(&str, result->coord, "Invalid coord for light", result))
		return ;
	if (!ft_read_ratio(&str, &result->ratio, result))
		return ;
	if (!ft_read_color(&str, &result->color, result))
		return ;
	element->content = result;
}

void		ft_parse_camera(char *str, t_element *element)
{
	t_camera	*result;

	element->content = NULL;
	if (!(result = (t_camera *)malloc(sizeof(t_camera))))
		ft_print_error("Malloc failed", 0, 1);
	if (!ft_read_coord(&str, result->view, "Invalid coord for camera", result))
		return ;
	if (!ft_read_norm(&str, result->orientation, "Invalid orientation", result))
		return ;
	if (!ft_check_fov(str, &result->fov))
	{
		ft_print_error("Invalid fov", 0, 0);
		free(result);
		return ;
	}
	element->content = result;
}
