/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 01:36:33 by rbourgea          #+#    #+#             */
/*   Updated: 2020/02/26 03:14:52 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_maths.h"

double			max(double a, double b)
{
	return (a < b ? b : a);
}

double			min(double a, double b)
{
	return (a > b ? b : a);
}

int				sign(double a)
{
	return (a < 0 ? -1 : 1);
}
