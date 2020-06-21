/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 23:35:31 by teyber            #+#    #+#             */
/*   Updated: 2020/06/09 16:30:12 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATHS_H
# define FT_MATHS_H

# include <math.h>
# include "ft_parser.h"
# include "ft_defs.h"

void				ft_rot_matrix(t_matrix33 result, t_vector unit, double fov);
void				ft_rotation(t_vector end, t_matrix33 rotmat,
		t_vector start);

void				ft_vector_add(t_vector result, t_vector a, t_vector b);
void				ft_vector_sub(t_vector result, t_vector a, t_vector b);
void				ft_vector_normalize(t_vector vector);
void				ft_vector_mult_lambda(t_vector res, t_vector a, double l);
double				ft_vector_dot(t_vector a, t_vector b);
void				ft_vector_cross(t_vector result, t_vector a, t_vector b);
double				ft_vector_norm2(t_vector vector);
double				ft_vector_norm(t_vector vector);
void				ft_get_vector(t_vector result, t_vector a, t_vector b);
void				ft_ray_point(t_vector point, t_ray *ray, double t);

int					ft_quadratic(double coeff[3], double *t1, double *t2);
int					ft_resolv_object(t_element *object, t_ray *ray,
		t_intersect *intersect);
int					ft_resolv_sphere(void *object, t_ray *ray,
		t_intersect *intersect);
int					ft_resolv_cylinder(void *object, t_ray *ray,
		t_intersect *intersect);
int					ft_resolv_square(void *object, t_ray *ray,
		t_intersect *intersect);
int					ft_resolv_triangle(void *object, t_ray *ray,
		t_intersect *intersect);
int					ft_resolv_plane(void *object, t_ray *ray,
		t_intersect *intersect);
int					ft_resolv_circle(void *object, t_ray *ray,
		t_intersect *intersect);
int					ft_resolv_ellipsoid(void *object, t_ray *ray,
		t_intersect *intersect);

t_ray				*ft_cast_cam_ray(t_scene *scene, int pcoord[2]);
double				min(double a, double b);
double				max(double a, double b);
int					sign(double a);

#endif
