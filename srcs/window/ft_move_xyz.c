/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_xyz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 13:48:44 by rbourgea          #+#    #+#             */
/*   Updated: 2020/02/01 17:53:49 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_window.h"

void	ft_move_xyz(t_data *data, int mode, int coef,
		void (*ft_modify_struct[9])(void *, int, double))
{
	t_element	*target;
	double		delta;
	int			id;

	target = NULL;
	delta = ((mode < 3) ? 1 : M_PI / 180) * coef;
	if (data->mode->type == TYPE_MODE_CAMERAS)
		target = data->scene->cameras->content;
	else if (data->mode->type == TYPE_MODE_LIGHTS)
		target = data->scene->lights->content;
	else if (data->mode->type == TYPE_MODE_GEOMETRICALS)
		target = data->scene->geometricals->content;
	if (!target || (id = ft_check_id(target->id)) == FT_PARSE_RESOLUTION ||
		id == FT_PARSE_AMBIENT_LIGHT || id == FT_PARSE_DEFAULT)
		return ;
	ft_modify_struct[id](target->content, mode, delta);
}
