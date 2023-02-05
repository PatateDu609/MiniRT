/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:06:37 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/23 22:55:49 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "ft_window.h"
#include "ft_maths.h"
#include "debug.h"
#include <stdio.h>

char			*g_program_name;

static int ft_usage(void)
{
	fprintf(stderr, "Usage: %s <scene .rt> [-save/-png]", g_program_name);
	exit(1);
	return (1);
}

static int get_target(int ac, char **av)
{
	if (ac == 2)
		return 0;

	char *arg = av[2];

	if (!strncmp(arg, "-save", 5))
		return 0;
	if (!strncmp(arg, "-png", 4))
		return 1;

	return -1;
}

int				main(int ac, char **av)
{
	t_scene		*scene;
	char		*e;

	e = "A scene needs at least a camera, an ambiance light and a resolution";
	if (!(ac == 2 || ac == 3))
		return ft_usage();
	int target = get_target(ac, av);

	if (target < 0)
		return ft_usage();

	scene = ft_init_scene();
	g_program_name = strrchr(av[0], '/') + 1;

	if (ft_parser(av[1], scene) <= 0)
	{
		ft_destroy_scene(scene);
		return (1);
	}

	if (!ft_check_scene(scene))
	{
		ft_destroy_scene(scene);
		ft_print_error(e, 0, 1);
	}
	ft_render(scene, target);
	ft_destroy_scene(scene);
	return (0);
}
