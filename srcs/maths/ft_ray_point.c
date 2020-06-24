/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:35:55 by rbourgea          #+#    #+#             */
/*   Updated: 2020/02/22 21:37:26 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"

void	ft_ray_point(t_vector point, t_ray *ray, double t)
{
	point[0] = ray->origin[0] + ray->direct[0] * t;
	point[1] = ray->origin[1] + ray->direct[1] * t;
	point[2] = ray->origin[2] + ray->direct[2] * t;
}
