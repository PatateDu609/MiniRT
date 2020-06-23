/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:06:37 by gboucett          #+#    #+#             */
/*   Updated: 2020/06/23 22:55:49 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_parser.h"
#include "ft_window.h"
#include "ft_maths.h"
#include "debug.h"
#include <stdio.h>

static int		ft_test_arg(int ac, char **av, char *arg)
{
	int		len;
	int		len1;

	if (ac == 2)
		return (0);
	len = ft_strlen(arg);
	len1 = ft_strlen(av[2]);
	if (len != len1 || ft_strncmp(arg, av[2], len))
		return (0);
	return (1);
}

#ifndef BONUS

static int		ft_issave(int ac, char **av)
{
	if (ft_test_arg(ac, av, "-save") || ft_test_arg(ac, av, "--save"))
		return (1);
	return (0);
}

#else

static int		ft_issave(int ac, char **av)
{
	if (ft_test_arg(ac, av, "-png"))
		return (2);
	else if (ft_test_arg(ac, av, "-save") || ft_test_arg(ac, av, "--save"))
		return (1);
	return (0);
}

#endif

int				main(int ac, char **av)
{
	t_scene		*scene;
	char		*e;

	e = "A scene needs at least a camera, an ambiance light and a resolution";
	if (ac == 1)
		return (1);
	scene = ft_init_scene();
	g_program_name = ft_strrchr(av[0], '/') + 1;
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
	ft_render(scene, ft_issave(ac, av));
	ft_destroy_scene(scene);
	return (0);
}
