/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:56:30 by gboucett          #+#    #+#             */
/*   Updated: 2020/06/21 22:47:43 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int			ft_check_fov(char *str, double *fov)
{
	if (!ft_special_strchr(str, "0123456789\n\t\v\f\r "))
		return (0);
	*fov = ft_atoi(str) * M_PI / 180.;
	return (0 <= *fov && *fov <= 180);
}

int			ft_count_color_fields(char *str)
{
	int		fields;

	fields = 1;
	while (*str)
	{
		if (*str == ',')
			fields++;
		str++;
	}
	return (fields == 3);
}
