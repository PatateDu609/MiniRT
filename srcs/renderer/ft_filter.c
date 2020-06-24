/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 22:53:17 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/23 22:53:32 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_renderer.h"

unsigned int	ft_filter(int filter, unsigned int color)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	t_vector		result;

	if (filter == NO_FILTER)
		return (color);
	ft_hexa_to_rgb(color, &r, &g, &b);
	if (filter == FILTER_GRAYSCALE)
	{
		result[0] = r * .2126 + g * .7152 + b * .0722;
		result[1] = r * .2126 + g * .7152 + b * .0722;
		result[2] = r * .2126 + g * .7152 + b * .0722;
	}
	else if (filter == FILTER_SEPIA)
	{
		result[0] = r * .393 + g * .769 + b * .189;
		result[1] = r * .349 + g * .686 + b * .168;
		result[2] = r * .272 + g * .534 + b * .131;
	}
	else
		return (color);
	return (ft_rgb_to_hexa(min(255, result[0]), min(255, result[1]), min(255,
		result[2])));
}
