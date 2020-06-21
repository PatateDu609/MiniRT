/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_cam_ray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:27:44 by gboucett          #+#    #+#             */
/*   Updated: 2020/06/19 22:53:06 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"
#include "debug.h"

void	ft_look_at_2(t_matrix44 ctw, t_vector forward,
	t_vector right, t_vector up)
{
	ctw[0][3] = 0;
	ctw[1][3] = 0;
	ctw[2][3] = 0;
	ctw[3][3] = 1;
	ft_memcpy(ctw[0], right, sizeof(t_vector));
	ft_memcpy(ctw[1], up, sizeof(t_vector));
	ft_memcpy(ctw[2], forward, sizeof(t_vector));
}

void	ft_look_at(t_matrix44 ctw, t_camera *camera)
{
	t_vector	forward;
	t_vector	right;
	t_vector	up;
	t_vector	tmp;

	ft_vector_add(tmp, camera->orientation, camera->view);
	ft_vector_sub(forward, tmp, camera->view);
	ft_vector_normalize(forward);
	tmp[0] = 0;
	tmp[1] = 1;
	tmp[2] = 0;
	ft_vector_normalize(tmp);
	ft_vector_cross(right, tmp, forward);
	ft_vector_cross(up, forward, right);
	ft_look_at_2(ctw, forward, right, up);
	ft_memcpy(ctw[3], camera->view, sizeof(t_vector));
}

void	ft_mult_dir_matrix(t_matrix44 ctw, t_vector dir)
{
	dir[0] = dir[0] * ctw[0][0] + dir[1] * ctw[1][0] + dir[2] * ctw[2][0];
	dir[1] = dir[0] * ctw[0][1] + dir[1] * ctw[1][1] + dir[2] * ctw[2][1];
	dir[2] = dir[0] * ctw[0][2] + dir[1] * ctw[1][2] + dir[2] * ctw[2][2];
}

void	ft_mult_vec_matrix(t_matrix44 ctw, t_vector origin)
{
	t_hvector	hdirect;

	hdirect[3] = 1;
	ft_memcpy(hdirect, origin, sizeof(t_vector));
	hdirect[0] = origin[0] * ctw[0][0] + origin[1] * ctw[1][0] + origin[2]
		* ctw[2][0] + ctw[3][0];
	hdirect[1] = origin[0] * ctw[0][1] + origin[1] * ctw[1][1] + origin[2]
		* ctw[2][1] + ctw[3][1];
	hdirect[2] = origin[0] * ctw[0][2] + origin[1] * ctw[1][2] + origin[2]
		* ctw[2][2] + ctw[3][2];
	hdirect[3] = origin[0] * ctw[0][3] + origin[1] * ctw[1][3] + origin[2]
		* ctw[2][3] + ctw[3][3];
	origin[0] = hdirect[0] / hdirect[3];
	origin[1] = hdirect[1] / hdirect[3];
	origin[2] = hdirect[2] / hdirect[3];
}

/*
** n[0] = ratio / n[1] = scale
*/

t_ray	*ft_cast_cam_ray(t_scene *scene, int pcoord[2])
{
	double		n[2];
	t_ray		*ray;
	t_camera	*camera;
	t_element	*element;
	t_matrix44	ctw;

	if (!(ray = (t_ray *)malloc(sizeof(t_ray))))
		return (NULL);
	n[0] = scene->resol->width / (double)scene->resol->height;
	element = (t_element *)scene->cameras->content;
	camera = (t_camera *)element->content;
	ft_look_at(ctw, camera);
	ft_mult_vec_matrix(ctw, ray->origin);
	n[1] = tan(camera->fov / 2);
	ray->direct[0] = (2 * (pcoord[0] + 0.5) / (double)scene->resol->width - 1)
		* n[0] * n[1];
	ray->direct[1] = (1 - 2 * (pcoord[1] + 0.5) / (double)scene->resol->height)
		* n[1];
	ray->direct[2] = -1;
	ft_mult_dir_matrix(ctw, ray->direct);
	ft_vector_normalize(ray->direct);
	return (ray);
}
