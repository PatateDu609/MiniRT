/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:33:57 by gboucett          #+#    #+#             */
/*   Updated: 2020/12/24 21:41:59 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_maxcar_prec_null(int n, t_flags flags, int len, int mode)
{
	if (mode)
	{
		if (flags.precision == 0 && n == 0)
			return (ft_ternaryi(flags.length_def, 0, flags.length));
		else if (flags.length_def && flags.precision == F_DEF_PREC)
			return (len);
		else if (flags.precision != F_DEF_PREC
			&& flags.length <= flags.precision)
			return (flags.precision + (n < 0));
		return (flags.length);
	}
	else
	{
		if (flags.precision != 0 || n != 0)
			return (0);
		if (flags.length_def)
			return (0);
		else
			return (flags.length);
	}
}

static void	ft_print_spaces(int n, t_flags flags, int len, int fix)
{
	int		total;
	int		spaces;
	int		abs_len;

	spaces = 0;
	if (fix <= 0)
	{
		abs_len = len - (n < 0);
		total = flags.length - ft_ternaryi(flags.precision <= abs_len, len,
				flags.precision + (n < 0));
		while (spaces < total)
		{
			ft_putchar_fd(ft_ternaryi(flags.prefix == F_ZERO
					&& flags.precision == F_DEF_PREC, '0', ' '), 1);
			spaces++;
		}
	}
	else
	{
		while (spaces < fix)
		{
			write(1, " ", 1);
			spaces++;
		}
	}
}

static void	ft_print_zeroes_d(int len, t_flags flags, int sign)
{
	int		zeroes;

	zeroes = 0;
	while (zeroes < flags.precision - len + sign)
	{
		write(1, "0", 1);
		zeroes++;
	}
}

static void	ft_print_pre_nbr(int n, t_flags flags, int len)
{
	if (flags.alignment == F_RIGHT)
	{
		if (flags.prefix == F_NO_PREFIX || flags.precision != F_DEF_PREC)
			ft_print_spaces(n, flags, len,
				ft_maxcar_prec_null(n, flags, len, 0));
		if (n < 0)
			ft_putchar_fd('-', 1);
		if (!(flags.prefix == F_NO_PREFIX || flags.precision != F_DEF_PREC))
			ft_print_spaces(n, flags, len,
				ft_maxcar_prec_null(n, flags, len, 0));
		ft_print_zeroes_d(len, flags, n < 0);
	}
	else if (flags.alignment == F_LEFT)
	{
		if (n < 0)
			ft_putchar_fd('-', 1);
		ft_print_zeroes_d(len, flags, n < 0);
	}
}

int	ft_putnbr(int n, t_flags flags)
{
	int		maxcar;
	int		len;

	len = ft_size_base(n, 0, 10);
	maxcar = ft_maxcar_prec_null(n, flags, len, 1);
	if (flags.alignment == F_RIGHT)
	{
		ft_print_pre_nbr(n, flags, len);
		if (flags.precision != 0 || n != 0)
			ft_print_nbr(n < 0 ? -n : n);
	}
	else if (flags.alignment == F_LEFT)
	{
		ft_print_pre_nbr(n, flags, len);
		if (flags.precision != 0 || n != 0)
			ft_print_nbr(n < 0 ? -n : n);
		ft_print_spaces(n, flags, len, ft_maxcar_prec_null(n, flags, len, 0));
	}
	if (flags.precision == 0 && n == 0
		&& (flags.length_def || flags.length == 0))
		return (0);
	return (ft_ternaryi(len <= maxcar, maxcar, len));
}
