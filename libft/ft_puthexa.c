/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:09:24 by gboucett          #+#    #+#             */
/*   Updated: 2020/12/24 21:27:19 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_nbr_hexa(int mode, unsigned long n)
{
	if (n / 16)
		ft_print_nbr_hexa(mode, n / 16);
	ft_putchar_fd(ft_ternaryi(mode, "0123456789abcdef" [n % 16],
			"0123456789ABCDEF" [n % 16]), 1);
}

static void	ft_print_precision(int precision, int len)
{
	int		i;

	i = -1;
	while (++i < precision - len)
		write(1, "0", 1);
}

static void	ft_print_pref(t_flags flags, int len, unsigned long n)
{
	if (!flags.length_def && !flags.precision && !n)
		len = 0;
	ft_print_prefix(flags, len);
}

static void	ft_print_nb(unsigned long n, t_flags flags, int len, int mode)
{
	if (n != 0 || flags.precision != 0)
	{
		ft_print_precision(flags.precision, len);
		ft_print_nbr_hexa(mode, n);
	}
}

void	ft_puthexa(int mode, unsigned long n, int *size, t_flags flags)
{
	int		len;
	int		precision;

	precision = ft_ternaryi(flags.precision == F_DEF_PREC, 1, flags.precision);
	len = ft_size_base(n, 0, 16);
	if (flags.alignment == F_RIGHT)
	{
		ft_print_pref(flags, len, n);
		ft_print_nb(n, flags, len, mode);
	}
	else if (flags.alignment == F_LEFT)
	{
		ft_print_nb(n, flags, len, mode);
		ft_print_pref(flags, len, n);
	}
	if (precision == 0 && n == 0)
		*size = ft_ternaryi(flags.length_def, 0, flags.length);
	else if (len >= precision)
		*size = ft_ternaryi(flags.length <= len, len, flags.length);
	else
		*size = ft_ternaryi(precision <= flags.length, flags.length, precision);
}
