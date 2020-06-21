/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:32:18 by gboucett          #+#    #+#             */
/*   Updated: 2020/02/20 17:49:09 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"

void	ft_rot_matrix(t_matrix33 result, t_vector u, double angle)
{
	double	angle_c;
	double	angle_s;
	double	angle_c1;

	angle_c = cos(angle);
	angle_s = sin(angle);
	angle_c1 = 1 - angle_c;
	result[0][0] = u[0] * u[0] * angle_c1 + angle_c;
	result[0][1] = u[1] * u[0] * angle_c1 - u[2] * angle_s;
	result[0][2] = u[2] * u[0] * angle_c1 + u[1] * angle_s;
	result[1][0] = u[0] * u[1] * angle_c1 + u[2] * angle_s;
	result[1][1] = u[1] * u[1] * angle_c1 + angle_c;
	result[1][2] = u[2] * u[1] * angle_c1 - u[0] * angle_s;
	result[2][0] = u[0] * u[2] * angle_c1 - angle_s * u[1];
	result[2][1] = u[1] * u[2] * angle_c1 + angle_s * u[0];
	result[2][2] = u[2] * u[2] * angle_c1 + angle_c;
}
