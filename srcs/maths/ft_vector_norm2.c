/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_norm2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teyber <teyber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 01:13:49 by teyber            #+#    #+#             */
/*   Updated: 2019/12/24 01:16:09 by teyber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"

double		ft_vector_norm2(t_vector vector)
{
	return (pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2));
}
