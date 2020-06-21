/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:26:25 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/17 13:20:03 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "ft_parser.h"
# include "ft_printf.h"
# include "ft_window.h"
# include <stdio.h>

void ft_print_vector(t_vector vector);
void ft_print_element(t_element *element);
void ft_print_scene(t_scene *scene);
char *ft_translate_id(char *id);

void ft_print_resolution(t_element *element);
void ft_print_ambient_light(t_element *element);
void ft_print_light(t_element *element);
void ft_print_camera(t_element *element);
void ft_print_sphere(t_element *element);
void ft_print_square(t_element *element);
void ft_print_plane(t_element *element);
void ft_print_cylinder(t_element *element);
void ft_print_triangle(t_element *element);

void ft_print_selected(t_data *data);

#endif
