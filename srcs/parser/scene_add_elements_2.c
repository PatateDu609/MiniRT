/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_add_elements_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:52:28 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/20 23:43:59 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int			ft_add_element_2(t_scene *scene, t_element *element, int id)
{
	ft_affect_element(scene, element, id);
	if (id == FT_PARSE_RESOLUTION || id == FT_PARSE_AMBIENT_LIGHT)
	{
		free(element->id);
		free(element);
	}
	return (1);
}

int			ft_add_element(t_scene *scene, t_element *element)
{
	int		id;

	id = ft_check_id(element->id);
	if (id == FT_PARSE_FILTER)
	{
		scene->filter = *((int *)element->content);
		ft_del_element(element);
		return (-2);
	}
	if (id == FT_PARSE_RESOLUTION && scene->resol)
	{
		ft_del_element(element);
		return (0);
	}
	if (id == FT_PARSE_AMBIENT_LIGHT && scene->ambient)
	{
		ft_del_element(element);
		return (-1);
	}
	ft_add_element_2(scene, element, id);
	return (1);
}
