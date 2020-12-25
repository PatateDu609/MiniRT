/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:42:36 by gboucett          #+#    #+#             */
/*   Updated: 2020/12/23 18:43:17 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prefix(t_flags *flags, char current)
{
	if (flags->prefix == F_NO_PREFIX)
	{
		if (current == '0' && flags->alignment == F_RIGHT)
			flags->prefix = F_ZERO;
		else if (current == ' ')
			flags->prefix = F_SPACE;
	}
	else if (flags->prefix == F_ZERO && current == ' ')
		flags->prefix = ft_ternaryi(flags->alignment == F_LEFT, F_SPACE,
				F_ZERO_SPACE);
	else if (flags->prefix == F_SPACE && current == '0'
		&& flags->alignment == F_RIGHT)
		flags->prefix = F_ZERO_SPACE;
	else if (current == '-' && (flags->prefix == F_ZERO_SPACE
			|| flags->prefix == F_ZERO))
		flags->prefix = ft_ternaryi(flags->prefix == F_ZERO, F_NO_PREFIX,
				F_SPACE);
}

void	ft_alignment(t_flags *flags)
{
	if (flags->alignment == F_RIGHT)
	{
		flags->alignment = F_LEFT;
		ft_prefix(flags, '-');
	}
}

void	ft_flag_numbers(t_flags *flags, const char **str, int *waiting)
{
	int		result;

	result = ft_atoi(*str);
	while (**str && ft_isdigit(**str))
		*str += 1;
	*str -= 1;
	if (*waiting == W_LENGTH || *waiting == W_FIRST_FLAG)
	{
		flags->length = result;
		flags->length_def = 0;
		*waiting = W_POINT;
	}
	else if (*waiting == W_PRECISION)
	{
		flags->precision = result;
		*waiting = W_NOTHING;
	}
}

void	ft_star(t_flags *flags, int *waiting, va_list args)
{
	if (*waiting == W_LENGTH || *waiting == W_FIRST_FLAG)
	{
		flags->length = va_arg(args, int);
		flags->length_def = 0;
		*waiting = W_POINT;
	}
	else if (*waiting == W_PRECISION)
	{
		flags->precision = va_arg(args, int);
		if (flags->precision < 0)
			flags->precision = F_DEF_PREC;
		*waiting = W_NOTHING;
	}
}

t_flags	ft_parse(const char **str, va_list args)
{
	t_flags		flags;
	int			waiting;

	flags = (t_flags){F_RIGHT, 1, 1, F_DEF_PREC, F_NO_PREFIX, 0};
	waiting = W_FIRST_FLAG;
	while (**str && ft_isformat_or_flag(**str))
	{
		if (waiting == W_FIRST_FLAG && (**str == '0' || **str == ' '))
			ft_prefix(&flags, **str);
		else if (waiting == W_FIRST_FLAG && **str == '-')
			ft_alignment(&flags);
		else if (waiting != W_NOTHING && **str == '.')
			waiting = W_PRECISION;
		else if (**str == '*')
			ft_star(&flags, &waiting, args);
		else if (ft_isformat(**str))
			flags.conversion = **str;
		else if (ft_isdigit(**str))
			ft_flag_numbers(&flags, str, &waiting);
		if (flags.conversion)
			break ;
		*str += 1;
	}
	ft_update_flags(&flags, waiting);
	return (flags);
}
