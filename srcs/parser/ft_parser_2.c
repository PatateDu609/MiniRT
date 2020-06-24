/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 22:41:04 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/23 19:34:10 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "ft_printf.h"

int			ft_parser(char *scene_filename, t_scene *scene)
{
	char			*to_parse;
	t_element		*element;
	int				result;
	int				fd;

	fd = open(scene_filename, O_RDONLY);
	result = 1;
	while (get_next_line(fd, &to_parse))
	{
		if (ft_strlen(to_parse) > 0 && (element = ft_parse_line(to_parse)))
		{
			if ((result = ft_add_element(scene, element)) == 0 || result == -1)
			{
				ft_print_error(result == 0 ?
					"There can't be more than one resolution" :
					"There can't be more than one ambient light", 0, 0);
				break ;
			}
		}
		free(to_parse);
	}
	free(to_parse);
	close(fd);
	return (result);
}
