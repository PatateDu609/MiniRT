/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 22:41:04 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/23 19:34:20 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int			ft_segment_len(char *line)
{
	int		result;

	result = 0;
	if (*line == '#')
		return (1);
	while (*line && *line != ' ' && *line != '\t')
	{
		line++;
		result++;
	}
	return (result);
}

char		*ft_parse_identifier(char **line)
{
	char	*identifier;
	int		len;

	len = ft_segment_len(*line);
	identifier = ft_substr(*line, 0, len);
	*line += len;
	if (*identifier == '#')
		return (identifier);
	if (identifier && ft_check_id(identifier) != -1)
		return (identifier);
	if (identifier)
		free(identifier);
	return (NULL);
}

void		ft_parse_line_2(void (*ft_parsing[20])(char *, t_element *))
{
	ft_parsing[FT_PARSE_RESOLUTION] = &ft_parse_resolution;
	ft_parsing[FT_PARSE_AMBIENT_LIGHT] = &ft_parse_ambient_light;
	ft_parsing[FT_PARSE_LIGHT] = &ft_parse_light;
	ft_parsing[FT_PARSE_CAMERA] = &ft_parse_camera;
	ft_parsing[FT_PARSE_SPHERE] = &ft_parse_sphere;
	ft_parsing[FT_PARSE_SQUARE] = &ft_parse_square;
	ft_parsing[FT_PARSE_PLANE] = &ft_parse_plane;
	ft_parsing[FT_PARSE_CYLINDER] = &ft_parse_cylinder;
	ft_parsing[FT_PARSE_TRIANGLE] = &ft_parse_triangle;
	ft_parsing[FT_PARSE_CIRCLE] = &ft_parse_circle;
	ft_parsing[FT_PARSE_FILTER] = &ft_parse_filter;
	ft_parsing[FT_PARSE_ELLIPSOID] = &ft_parse_ellipsoid;
}

t_element	*ft_parse_line(char *line)
{
	t_element	*result;
	void		(*ft_parsing[20])(char *, t_element *);

	ft_parse_line_2(ft_parsing);
	if (!(result = (t_element *)malloc(sizeof(t_element))))
		return (NULL);
	if (!(result->id = ft_parse_identifier(&line)))
	{
		ft_print_error("Identifier needed", 0, 0);
		free(result);
		return (NULL);
	}
	else if (result->id[0] == '#')
	{
		free(result->id);
		free(result);
		return (NULL);
	}
	ft_skip_separator(&line, " \t");
	ft_parsing[ft_check_id(result->id)](line, result);
	return (result);
}
