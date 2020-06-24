/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:22:30 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/20 19:13:03 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_renderer.h"

int		ft_rgb_to_hexa(unsigned int r, unsigned int g, unsigned int b)
{
	return (r << 16 | g << 8 | b);
}

void	ft_hexa_to_rgb(unsigned int hex, unsigned int *r, unsigned int *g,
		unsigned int *b)
{
	*r = (hex & 0xFF0000) >> 16;
	*g = (hex & 0x00FF00) >> 8;
	*b = (hex & 0x0000FF);
}

/*
**	printf("%d, %d, %d %lf, %lf, %lf\n", r, g, b,
**	lambda[0], lambda[1], lambda[2]);
*/

int		ft_hex_mult(unsigned int hex, t_vector lambda)
{
	unsigned int		r;
	unsigned int		g;
	unsigned int		b;

	ft_hexa_to_rgb(hex, &r, &g, &b);
	r *= lambda[0];
	g *= lambda[1];
	b *= lambda[2];
	return (ft_rgb_to_hexa(r, g, b));
}
