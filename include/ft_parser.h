/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 22:42:36 by gboucett          #+#    #+#             */
/*   Updated: 2020/06/21 22:48:24 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include "libft.h"
# include "ft_defs.h"
# include "get_next_line.h"
# include <string.h>
# include <errno.h>
# include <math.h>
# include <fcntl.h>

t_scene				*ft_init_scene();
void				ft_destroy_scene(t_scene *scene);
int					ft_check_scene(t_scene *scene);
void				ft_del_element(void *element);

void				ft_add_geometrical(t_scene *scene, t_element *element);
void				ft_add_light(t_scene *scene, t_element *light);
void				ft_add_camera(t_scene *scene, t_element *camera);
void				ft_affect_element(t_scene *scene, t_element *elem, int id);
int					ft_add_element(t_scene *scene, t_element *element);

int					ft_splitted_len(char **strs);
void				ft_splitted_clear(char **strs);
int					ft_special_strchr(char *str, char *set);
double				ft_strtof(char *str);
void				ft_skip_separator(char **str, char *separator);

int					ft_check_id(char *identifier);
int					ft_check_color(char *str, unsigned int *color);
int					ft_check_vector(char *str, int normalized, t_vector vector);
int					ft_check_double(char *str, double *number, int ratio);
int					ft_check_fov(char *str, double *fov);
int					ft_count_color_fields(char *str);

int					ft_read_coord(char **str, t_vector res, char *err, void *f);
int					ft_read_norm(char **str, t_vector res, char *err, void *tf);
int					ft_read_color(char **str, unsigned int *res, void *tfree);
int					ft_read_ratio(char **current, double *result, void *tofree);

int					ft_read_double(char **s, double *res, char *err, void *tf);
void				ft_read_specular(char **s, unsigned int *col, double *shin);

void				ft_parse_resolution(char *str, t_element *element);
void				ft_parse_ambient_light(char *str, t_element *element);
void				ft_parse_light(char *str, t_element *element);
void				ft_parse_filter(char *str, t_element *element);
void				ft_parse_camera(char *str, t_element *element);

void				ft_parse_sphere(char *str, t_element *element);
void				ft_parse_square(char *str, t_element *element);
void				ft_parse_plane(char *str, t_element *element);
void				ft_parse_cylinder(char *str, t_element *element);
void				ft_parse_triangle(char *str, t_element *element);
void				ft_parse_circle(char *str, t_element *element);
void				ft_parse_ellipsoid(char *str, t_element *element);

int					ft_segment_len(char *line);
char				*ft_parse_identifier(char **line);
t_element			*ft_parse_line(char *line);
int					ft_parser(char *scene_filename, t_scene *scene);

void				ft_add_caps(t_scene *scene, t_cylinder *cylinder);

void				ft_print_error(char *str, int sys, int block);

#endif
