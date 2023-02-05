/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_defs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:58:11 by gboucett          #+#    #+#             */
/*   Updated: 2020/04/24 18:30:11 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEFS_H
# define FT_DEFS_H

# include "libft.h"
# include <stdio.h>
# include <strings.h>
# include <string.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846264338327950288
# endif

# ifndef M_PI_2
#  define M_PI_2 1.57079632679489661923
# endif

typedef double		t_vector[3];
typedef double		t_hvector[4];
typedef double		t_matrix33[3][3];
typedef double		t_matrix44[4][4];

extern char			*g_program_name;

# define LIGHT_INTENSITY	156250
# define MAX_THREADS		16

# define NO_FILTER			0
# define FILTER_SEPIA		1
# define FILTER_GRAYSCALE	2

/*
**	FT_PARSE_*				=	indexes of functions to parse each type of
**								object of rt file
*/

# define FT_PARSE_DEFAULT			-1
# define FT_PARSE_RESOLUTION		0
# define FT_PARSE_AMBIENT_LIGHT		1
# define FT_PARSE_LIGHT				2
# define FT_PARSE_CAMERA			3
# define FT_PARSE_SPHERE			4
# define FT_PARSE_SQUARE			5
# define FT_PARSE_PLANE				6
# define FT_PARSE_CYLINDER			7
# define FT_PARSE_TRIANGLE			8

/*
**	from this point, the defines are bonuses
*/
# define FT_PARSE_CIRCLE			9
# define FT_PARSE_ELLIPSOID			10
# define FT_PARSE_HYPERBOLOID		11
# define FT_PARSE_REVOLUTION_CONE	12
# define FT_PARSE_CUBE				13
# define FT_PARSE_PYRAMID			14

# define FT_PARSE_FILTER			15

/*
**	KEY_* = all the key code for the mlx
*/

# ifndef LINUX
#  define KEY_UP_ARROW			126
#  define KEY_DOWN_ARROW		125
#  define KEY_LEFT_ARROW		123
#  define KEY_RIGHT_ARROW		124
#  define KEY_COMMA				43
#  define KEY_POINT				47
#  define KEY_ESC				53
#  define KEY_Q					12
#  define KEY_W					13
#  define KEY_E					14
#  define KEY_F					3
# else
#  define KEY_UP_ARROW			65362
#  define KEY_DOWN_ARROW		65364
#  define KEY_LEFT_ARROW		65361
#  define KEY_RIGHT_ARROW		65363
#  define KEY_COMMA				44
#  define KEY_POINT				46
#  define KEY_ESC				65307
#  define KEY_Q					113
#  define KEY_W					119
#  define KEY_E					101
#  define KEY_F					102
# endif

/*
**	TYPE_MODE_* = all the modes for types of key bind
*/

# define TYPE_MODE_CAMERAS			0
# define TYPE_MODE_LIGHTS			1
# define TYPE_MODE_GEOMETRICALS		2

/*
**	MODE_* = all the modes for ft_modify_* functions
*/

# define MODE_COORD_X			0
# define MODE_COORD_Y			1
# define MODE_COORD_Z			2
# define MODE_ORIENTATION_X		3
# define MODE_ORIENTATION_Y		4
# define MODE_ORIENTATION_Z		5

# define DEFAULT_COLOR		0x000000

typedef struct		s_resolution
{
	int	width;
	int	height;
}					t_resolution;

typedef struct		s_light
{
	double			ratio;
	unsigned int	color;
	int				ambient;
	t_vector		coord;
}					t_light;

typedef struct		s_camera
{
	t_vector		view;
	t_vector		orientation;
	double			fov;
}					t_camera;

typedef struct		s_sphere
{
	t_vector		origin;
	double			diameter;
	unsigned int	color;
	double			shiny;
	unsigned int	spec_color;
}					t_sphere;

typedef struct		s_plane
{
	t_vector		coord;
	t_vector		normal;
	unsigned int	color;
	double			shiny;
	unsigned int	spec_color;
}					t_plane;

typedef struct		s_square
{
	t_vector		coord;
	t_vector		normal;
	double			size;
	unsigned int	color;
	double			shiny;
	unsigned int	spec_color;
	int				first_pass;
	t_vector		points[4];
}					t_square;

typedef struct		s_circle
{
	t_vector		coord;
	t_vector		normal;
	double			diameter;
	unsigned int	color;
	int				writable;
	double			shiny;
	unsigned int	spec_color;
}					t_circle;

typedef struct		s_cylinder
{
	t_vector		coord;
	t_vector		orient;
	double			diameter;
	double			height;
	unsigned int	color;
	int				caps;
	t_circle		*cap_shape[2];
	double			shiny;
	unsigned int	spec_color;
}					t_cylinder;

typedef struct		s_triangle
{
	t_vector		coord[3];
	unsigned int	color;
	double			shiny;
	unsigned int	spec_color;
}					t_triangle;

typedef struct		s_ellipsoid
{
	t_vector		coord;
	t_vector		coeffs;
	unsigned int	color;
	double			shiny;
	unsigned int	spec_color;
}					t_ellipsoid;

typedef struct		s_element
{
	char			*id;
	void			*content;
}					t_element;

typedef struct		s_scene
{
	t_resolution	*resol;
	t_light			*ambient;
	int				filter;
	t_list			*lights;
	t_list			*cameras;
	int				cur_camera;
	int				nb_cameras;
	t_list			*geometricals;
}					t_scene;

typedef struct		s_ray
{
	t_vector		origin;
	t_vector		direct;
}					t_ray;

typedef struct		s_intersect
{
	t_vector		pos;
	t_element		*element;
	t_vector		normal;
	double			param;
}					t_intersect;

typedef struct		s_key_mode
{
	int				arrow;
	int				type;
}					t_key_mode;

typedef struct		s_data
{
	unsigned int	*img_addr;
	int				target;
	int				tr;
	t_scene			*scene;
	t_key_mode		*mode;
}					t_data;

typedef struct		s_thread_data
{
	t_data			*data;
	int				pcoord[2];
	int				size[2];
}					t_thread_data;

typedef struct		s_thread
{
	int				cur_thr;
	t_data			scene;
}					t_thread;

#endif
