/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:43:45 by teyber            #+#    #+#             */
/*   Updated: 2020/06/23 23:16:34 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RENDERER_H
# define FT_RENDERER_H

# include "ft_parser.h"
# include "ft_printf.h"
# include "ft_maths.h"
# include "mlx.h"
# include <pthread.h>

void			ft_ray_tracing(t_data *data);
void			ft_draw_pixel(t_data *data, int pixel_coord[2], int w, int h);
void			ft_redraw_window(t_data *data);
void			ft_save(unsigned int *data, int width, int height);
int				ft_intersect(t_scene *scene, t_ray *ray, t_intersect *inter);

unsigned int	ft_get_object_color(t_element *element);
unsigned int	ft_get_sphere_color(void *sphere);
unsigned int	ft_get_square_color(void *square);
unsigned int	ft_get_plane_color(void *plane);
unsigned int	ft_get_triangle_color(void *triangle);
unsigned int	ft_get_cylinder_color(void *cylinder);

unsigned int	ft_lambertian(t_light *light, t_intersect *intersect);
unsigned int	ft_color(t_scene *scene, t_intersect *intersect);
unsigned int	ft_shadow(t_scene *scene, t_light *light, t_intersect *inter);
void			*ft_get_element(t_list *list);
unsigned int	ft_ambient(t_light *ambient, t_element *element);
unsigned int	ft_add_color(unsigned int ca, unsigned int cb);

int				ft_rgb_to_hexa(unsigned int r, unsigned int g, unsigned int b);
int				ft_hex_mult(unsigned int hex, double lambda[3]);
void			ft_hexa_to_rgb(unsigned int hex, unsigned int *r,
		unsigned int *g, unsigned int *b);

# ifdef BONUS

unsigned int	ft_filter(int filter, unsigned int color);

unsigned int	ft_get_circle_color(void *circle);
unsigned int	ft_get_ellipsoid_color(void *ellipsoid);

double			ft_get_object_shiny(t_element *element);
double			ft_get_sphere_shiny(void *sphere);
double			ft_get_square_shiny(void *square);
double			ft_get_plane_shiny(void *plane);
double			ft_get_triangle_shiny(void *triangle);
double			ft_get_cylinder_shiny(void *cylinder);
double			ft_get_circle_shiny(void *circle);
double			ft_get_ellipsoid_shiny(void *ellipsoid);

unsigned int	ft_get_object_spec_color(t_element *element);
unsigned int	ft_get_sphere_spec_color(void *sphere);
unsigned int	ft_get_square_spec_color(void *square);
unsigned int	ft_get_plane_spec_color(void *plane);
unsigned int	ft_get_triangle_spec_color(void *triangle);
unsigned int	ft_get_cylinder_spec_color(void *cylinder);
unsigned int	ft_get_circle_spec_color(void *circle);
unsigned int	ft_get_ellipsoid_spec_color(void *ellipsoid);

unsigned int	ft_specular(t_vector cp, t_light *light,
				t_intersect *intersect);

void			ft_save_png(unsigned int *data, int width, int height);

# endif

#endif
