################################################################################
#                               Name of the output                             #
################################################################################
NAME				=	miniRT

################################################################################
#                          Paths of sources and objects                        #
################################################################################
PATH_INCLUDES		=	include
PATH_SRCS			=	srcs
PATH_OBJS			=	objs
PATH_LIBS			=	libs

################################################################################
#                                 Libft's infos                                #
################################################################################
LIBFT_PATH			=	libft
LIBFT_MAKE			=	Makefile
LIBFT				=	$(PATH_LIBS)/libft.a

################################################################################
#                                   libs infos                                 #
################################################################################

LIBATTOPNG_PATH		=	libattopng

################################################################################
#                              Name of sources files                           #
################################################################################
PATH_PARSER			=	parser
PATH_DEBUG			=	debug
PATH_WINDOW			=	window
PATH_MATHS			=	maths
PATH_RENDERER		=	renderer

RENDERER_SRCS		=	ft_ray_tracing			\
						ft_filter				\
						ft_draw					\
						ft_save					\
						ft_save_png				\
						ft_intersect			\
						ft_intersect_2			\
						ft_color_utils			\
						ft_get_object_utils		\
						ft_get_sphere_utils		\
						ft_get_cylinder_utils	\
						ft_get_plane_utils		\
						ft_get_square_utils		\
						ft_get_triangle_utils	\
						ft_get_circle_utils		\
						ft_get_ellipsoid_utils

MATHS_SRCS			=	ft_vector_normalize		\
						ft_vector_norm2			\
						ft_vector_norm			\
						ft_vector_add			\
						ft_vector_sub			\
						ft_vector_dot			\
						ft_vector_mult_lambda	\
						ft_rot_matrix			\
						ft_rotation				\
						ft_cast_cam_ray			\
						ft_resolv_object		\
						ft_resolv_sphere		\
						ft_resolv_square		\
						ft_resolv_plane			\
						ft_resolv_cylinder		\
						ft_resolv_triangle		\
						ft_resolv_circle		\
						ft_resolv_ellipsoid		\
						ft_quadratic			\
						utils					\
						ft_get_vector			\
						ft_vector_cross			\
						ft_ray_point

WINDOW_SRCS			=	ft_window				\

PARSER_SRCS			=	ft_parser					\
						ft_parser_2					\
						ft_parser_meta				\
						ft_parser_meta_utils		\
						ft_parser_geometric			\
						ft_parser_geometric_2		\
						ft_parser_geometric_other	\
						ft_parser_geometric_utils	\
						check_parse					\
						check_parse_2				\
						check_parse_utils			\
						scene_utils					\
						scene_add_elements			\
						scene_add_elements_2		\
						ft_add_caps

# DEBUG_SRCS			=	print_structs			\
# 						print_structs_2			\
# 						print_structs_3			\
# 						print_structs_4			\
# 						ft_print_selected

# SRCS_BASENAME		+=	$(addprefix $(PATH_DEBUG)/, $(DEBUG_SRCS))
SRCS_BASENAME		+=	$(addprefix $(PATH_PARSER)/, $(PARSER_SRCS))
SRCS_BASENAME		+=	$(addprefix $(PATH_WINDOW)/, $(WINDOW_SRCS))
SRCS_BASENAME		+=	$(addprefix $(PATH_MATHS)/, $(MATHS_SRCS))
SRCS_BASENAME		+=	$(addprefix $(PATH_RENDERER)/, $(RENDERER_SRCS))

SRCS_BASENAME		+=	main			\
						ft_print_error

################################################################################
#                             Commands and arguments                           #
################################################################################
RM					=	rm -f
GCC					=	gcc
CFLAGS				=	-I$(PATH_INCLUDES) -I$(LIBATTOPNG_PATH) -g3 -Wall -Werror -Wextra
LDFLAGS				=	-L$(PATH_LIBS) -lft -lm

LDFLAGS				+=	-g3 -ggdb

################################################################################
#                         DO NOT MODIFY BELOW THIS POINT                       #
################################################################################
SRCS_EXT			=	$(addsuffix .c, $(SRCS_BASENAME))

SRCS				=	$(addprefix $(PATH_SRCS)/, $(SRCS_EXT))
OBJS				=	$(addprefix $(PATH_OBJS)/, $(SRCS_EXT:.c=.o))

OS					=	$(shell uname -o)
ifeq ($(OS), GNU/Linux)
	CFLAGS			+=	-DLINUX
endif


$(PATH_OBJS)/%.o:	$(PATH_SRCS)/%.c
					$(GCC) $(CFLAGS) -c $< -o $@

$(NAME):			$(OBJS) $(LIBFT)
					$(GCC) -c $(LIBATTOPNG_PATH)/libattopng.c -o $(LIBATTOPNG_PATH)/libattopng.o
					$(GCC) $(OBJS) $(LIBATTOPNG_PATH)/libattopng.o -o $(NAME) $(LDFLAGS)

$(LIBFT):
					make -C $(LIBFT_PATH) -f $(LIBFT_MAKE)

$(MINILIBX):
					make -C $(MINILIBX_PATH) -f $(MINILIBX_MAKE)

all:				$(NAME)

libft:				$(LIBFT)

clean:
					$(RM) $(OBJS)
					make -C $(LIBFT_PATH) -f $(LIBFT_MAKE) clean

fclean:				clean
					$(RM) $(NAME)
					make -C $(LIBFT_PATH) -f $(LIBFT_MAKE) fclean


re:					fclean $(NAME)

.PHONY:				all clean fclean re gnl libft
