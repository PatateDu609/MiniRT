/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:34:15 by gboucett          #+#    #+#             */
/*   Updated: 2020/12/24 21:55:08 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_prec_null(t_flags flags)
{
	int		spaces;

	if (flags.length_def)
		return ;
	spaces = 0;
	while (spaces < flags.length)
	{
		write(1, " ", 1);
		spaces++;
	}
}

void	ft_putunsigned(unsigned int n, int *size, t_flags flags)
{
	int		len;
	int		precision;

	precision = ft_ternaryi(flags.precision == F_DEF_PREC, 1, flags.precision);
	len = ft_size_base(n, 0, 10);
	if (flags.alignment == F_RIGHT && (precision != 0 || n != 0))
	{
		ft_print_prefix(flags, len);
		ft_print_zeroes(len, precision);
		ft_print_nbr(n);
	}
	else if (flags.alignment == F_LEFT && (precision != 0 || n != 0))
	{
		ft_print_zeroes(len, precision);
		ft_print_nbr(n);
		ft_print_prefix(flags, len);
	}
	else
		ft_print_prec_null(flags);
	if (precision == 0 && n == 0)
		*size = ft_ternaryi(flags.length_def, 0, flags.length);
	else if (len >= precision)
		*size = ft_ternaryi(flags.length <= len, len, flags.length);
	else
		*size = ft_ternaryi(precision <= flags.length, flags.length, precision);
}
