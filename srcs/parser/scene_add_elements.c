/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_add_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 15:52:28 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/23 22:42:11 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

#ifndef BONUS

void		ft_add_geometrical(t_scene *scene, t_element *element)
{
	t_list		*new;

	if (!element)
		return ;
	if (!(new = ft_lstnew(element)))
		return ;
	ft_lstadd_back(&scene->geometricals, new);
}

#else

void		ft_add_geometrical(t_scene *scene, t_element *element)
{
	t_list		*new;

	if (!element)
		return ;
	if (!(new = ft_lstnew(element)))
		return ;
	ft_lstadd_back(&scene->geometricals, new);
	if (ft_check_id(element->id) == FT_PARSE_CYLINDER && element->content)
		ft_add_caps(scene, element->content);
}

#endif

void		ft_add_light(t_scene *scene, t_element *light)
{
	t_list		*new;

	if (!light)
		return ;
	if (!(new = ft_lstnew(light)))
		return ;
	ft_lstadd_back(&scene->lights, new);
}

void		ft_add_camera(t_scene *scene, t_element *camera)
{
	t_list		*new;

	if (!camera)
		return ;
	if (!(new = ft_lstnew(camera)))
		return ;
	ft_lstadd_back(&scene->cameras, new);
	scene->nb_cameras++;
}

void		ft_affect_element(t_scene *scene, t_element *element, int id)
{
	if (id == FT_PARSE_RESOLUTION)
		scene->resol = element->content;
	else if (id == FT_PARSE_AMBIENT_LIGHT)
		scene->ambient = element->content;
	else if (id == FT_PARSE_CAMERA)
		ft_add_camera(scene, element);
	else if (id == FT_PARSE_LIGHT)
		ft_add_light(scene, element);
	else
		ft_add_geometrical(scene, element);
}
