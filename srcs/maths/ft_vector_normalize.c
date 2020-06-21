/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_normalize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 01:16:24 by teyber            #+#    #+#             */
/*   Updated: 2020/02/06 19:47:48 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"

void	ft_vector_normalize(t_vector vector)
{
	double		norm;

	norm = sqrt(ft_vector_norm2(vector));
	if (!norm)
		return ;
	vector[0] /= norm;
	vector[1] /= norm;
	vector[2] /= norm;
}
