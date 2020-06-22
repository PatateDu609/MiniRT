/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:14:12 by teyber            #+#    #+#             */
/*   Updated: 2020/06/22 13:55:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WINDOW_H
# define FT_WINDOW_H

# include "ft_parser.h"
# include "mlx.h"
# include "ft_defs.h"
# include "ft_renderer.h"

void				ft_move_xyz(t_data *data, int mode, int coef,
		void (*ft_modify_struct[9])(void *, int, double));

void				ft_modify_sphere(void *element, int mode, double delta);
void				ft_modify_plane(void *element, int mode, double delta);
void				ft_modify_square(void *element, int mode, double delta);
void				ft_modify_cylinder(void *element,
		int mode, double delta);

void				ft_modify_camera(void *element, int mode, double delta);
void				ft_modify_light(void *element, int mode, double delta);

void				ft_modify_unique(t_element *element, int mode, int coeff);

int					ft_identify_arrows(int keycode);
void				ft_keydown_arrows(int arrows, t_data *data);

void				ft_next_cam(t_data *data);
void				ft_next_geo(t_data *data);
void				ft_next_light(t_data *data);

void				ft_prev_cam(t_data *data);
void				ft_prev_geo(t_data *data);
void				ft_prev_light(t_data *data);

void				ft_render(t_scene *scene, int file);
void				ft_window(t_data *data);
void				ft_set_size(t_data *data, int *width, int *height);


#endif
