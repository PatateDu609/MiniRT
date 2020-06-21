/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:53:11 by gboucett          #+#    #+#             */
/*   Updated: 2020/02/03 21:54:27 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"

void	ft_rotation(t_vector end, t_matrix33 rotmat, t_vector start)
{
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		end[i] = 0;
		j = 0;
		while (j < 3)
		{
			end[i] += rotmat[i][j] * start[j];
			j++;
		}
		i++;
	}
}
