/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:56:33 by gboucett          #+#    #+#             */
/*   Updated: 2020/01/27 13:54:50 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

t_scene		*ft_init_scene(void)
{
	t_scene		*scene;

	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
	scene->ambient = NULL;
	scene->resol = NULL;
	scene->nb_cameras = 0;
	scene->lights = NULL;
	scene->geometricals = NULL;
	scene->cameras = NULL;
	return (scene);
}

void		ft_del_element(void *element)
{
	t_element	*elem;

	elem = (t_element *)element;
	free(elem->id);
	free(elem->content);
	free(elem);
}

void		ft_destroy_scene(t_scene *scene)
{
	if (!scene)
		return ;
	if (scene->ambient)
		free(scene->ambient);
	if (scene->resol)
		free(scene->resol);
	ft_lstclear(&scene->cameras, &ft_del_element);
	ft_lstclear(&scene->lights, &ft_del_element);
	ft_lstclear(&scene->geometricals, &ft_del_element);
	free(scene);
}

int			ft_check_scene(t_scene *scene)
{
	if (scene->resol && scene->nb_cameras && scene->ambient)
		return (1);
	return (0);
}
