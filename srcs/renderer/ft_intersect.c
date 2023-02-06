/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:04:45 by rbourgea          #+#    #+#             */
/*   Updated: 2023/02/06 10:28:36 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_renderer.h"
#include "debug.h"

int				ft_intersect(t_scene *scene, t_ray *ray, t_intersect *intersect)
{
	t_intersect		local;
	t_list			*objects;
	int				has_inter_local;
	double			min_t;
	int				has_inter;

	objects = ft_lstfirst(scene->geometricals);
	has_inter = 0;
	min_t = 1E99;
	while (objects)
	{
		has_inter_local = ft_resolv_object(objects->content, ray, &local);
		if (has_inter_local && local.param < min_t)
		{
			has_inter = 1;
			min_t = local.param;
			if (intersect)
				memcpy(intersect, &local, sizeof(t_intersect));
		}
		objects = objects->next;
	}
	return (has_inter);
}

/*
** rgb = r / g / b
** dn = dot / normal_pose_p
*/

unsigned int	ft_lambertian(t_light *light, t_intersect *intersect)
{
	t_vector		intensity;
	t_vector		pos_p;
	unsigned	int	rgb[3];
	double			dn[2];
	t_vector		real_light;

	ft_vector_sub(pos_p, light->coord, intersect->pos);
	dn[1] = ft_vector_norm2(pos_p);
	ft_vector_normalize(pos_p);
	ft_vector_normalize(intersect->normal);
	dn[0] = ft_vector_dot(pos_p, intersect->normal);
	ft_hexa_to_rgb(light->color, &rgb[0], &rgb[1], &rgb[2]);
	real_light[0] = LIGHT_INTENSITY * light->ratio * (rgb[0] / 255 / M_PI);
	real_light[1] = LIGHT_INTENSITY * light->ratio * (rgb[1] / 255 / M_PI);
	real_light[2] = LIGHT_INTENSITY * light->ratio * (rgb[2] / 255 / M_PI);
	ft_hexa_to_rgb(ft_get_object_color(intersect->element),
		&rgb[0], &rgb[1], &rgb[2]);
	intensity[0] = rgb[0] * real_light[0] * max(0., dn[0]) / (4 * M_PI * dn[1]);
	intensity[1] = rgb[1] * real_light[1] * max(0., dn[0]) / (4 * M_PI * dn[1]);
	intensity[2] = rgb[2] * real_light[2] * max(0., dn[0]) / (4 * M_PI * dn[1]);
	return (ft_rgb_to_hexa(min(255., max(0., intensity[0])), min(255., max(0.,
		intensity[1])), min(255., max(0., intensity[2]))));
}

void			ft_specular_2(t_vector view,
		t_intersect *intersect, t_vector lp, t_vector reflect)
{
	ft_vector_normalize(lp);
	ft_vector_mult_lambda(reflect, intersect->normal, 2. *
		ft_vector_dot(intersect->normal, lp));
	ft_vector_sub(reflect, reflect, lp);
	ft_vector_normalize(view);
	ft_vector_normalize(reflect);
}

/*
** n[0] = view / n[1] = reflect / n[2] = lp / n[3] = intensity
*/

unsigned int	ft_specular(t_vector cp, t_light *light, t_intersect *intersect)
{
	double			shiny;
	t_vector		n[4];
	unsigned	int	rgb[4];
	t_vector		real_light;

	shiny = ft_get_object_shiny(intersect->element);
	ft_vector_sub(n[0], cp, intersect->pos);
	ft_vector_sub(n[2], light->coord, intersect->pos);
	ft_specular_2(n[0], intersect, n[2], n[1]);
	ft_hexa_to_rgb(light->color, &rgb[0], &rgb[1], &rgb[2]);
	real_light[0] = 255 * light->ratio * (rgb[1] / 255.);
	real_light[1] = 255 * light->ratio * (rgb[2] / 255.);
	real_light[2] = 255 * light->ratio * (rgb[3] / 255.);
	ft_hexa_to_rgb(ft_get_object_spec_color(intersect->element), &rgb[0],
		&rgb[1], &rgb[2]);
	n[3][0] = (rgb[0] / 255.) * real_light[0] * pow(ft_vector_dot(n[1],
		n[0]), shiny);
	n[3][1] = (rgb[1] / 255.) * real_light[1] * pow(ft_vector_dot(n[1],
		n[0]), shiny);
	n[3][2] = (rgb[2] / 255.) * real_light[2] * pow(ft_vector_dot(n[1],
		n[0]), shiny);
	return (ft_rgb_to_hexa(min(255., max(0., n[3][0])), min(255., max(0.,
		n[3][1])), min(255., max(0., n[3][2]))));
}

unsigned int	ft_color(t_scene *scene, t_intersect *intersect)
{
	t_list			*current;
	t_light			*light;
	unsigned int	color;
	unsigned int	fcolor;
	t_vector		cam_pos;

	current = ft_lstfirst(scene->lights);
	fcolor = ft_ambient(scene->ambient, intersect->element);
	memcpy(cam_pos, ((t_camera *)ft_get_element(scene->cameras))->view,
		sizeof(t_vector));
	while (current)
	{
		light = (t_light *)ft_get_element(current);
		color = ft_lambertian(light, intersect);
		if (ft_get_object_shiny(intersect->element) > 1)
			color = ft_add_color(color, ft_specular(cam_pos, light, intersect));
		fcolor = ft_add_color(fcolor, color * ft_shadow(scene, light,
			intersect));
		current = current->next;
	}
	return (fcolor);
}
