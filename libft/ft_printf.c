/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:14:16 by gboucett          #+#    #+#             */
/*   Updated: 2020/12/24 21:18:27 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_update_flags(t_flags *flags, int waiting)
{
	if (waiting == W_NOTHING && flags->length < 0)
	{
		flags->length *= -1;
		flags->alignment = F_LEFT;
		flags->prefix = ft_ternaryi(flags->prefix == F_ZERO, F_SPACE,
				F_NO_PREFIX);
	}
	if (flags->precision == F_DEF_PREC && waiting == W_PRECISION)
		flags->precision = 0;
}

static int	ft_print(t_flags flags, va_list args)
{
	int		result;
	char	conv;

	conv = flags.conversion;
	result = 0;
	if (conv == 'c' || conv == '%')
		result += ft_putchar(ft_ternaryi(conv == '%', '%', va_arg(args, int)),
				flags);
	else if (conv == 's')
	{
		result += ft_putstrr(va_arg(args, const char *), flags);
	}
	else if (conv == 'u')
		ft_putunsigned(va_arg(args, unsigned int), &result, flags);
	else if (conv == 'd' || conv == 'i')
		result += ft_putnbr(va_arg(args, int), flags);
	else if (conv == 'x' || conv == 'X')
		ft_puthexa(conv == 'x', va_arg(args, unsigned int), &result, flags);
	else if (conv == 'p')
		result += ft_putptr(va_arg(args, void*), flags);
	return (result);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			printed;
	t_flags		flags;

	va_start(args, str);
	printed = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			flags = ft_parse(&str, args);
			ft_update_flags(&flags, W_NOTHING);
			printed += ft_print(flags, args);
			str++;
		}
		else
			printed += write(1, str++, 1);
	}
	va_end(args);
	return (printed);
}
