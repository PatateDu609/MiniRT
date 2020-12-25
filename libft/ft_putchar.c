/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:34:27 by gboucett          #+#    #+#             */
/*   Updated: 2020/12/25 12:16:55 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, t_flags flags)
{
	int		spaces;
	char	*disp;

	spaces = 0;
	disp = ft_ternary(flags.prefix == F_ZERO || flags.prefix == F_ZERO_SPACE,
			"0", " ");
	if (flags.alignment == F_RIGHT)
	{
		while (spaces < flags.length - 1)
		{
			write(1, disp, 1);
			spaces++;
		}
		write(1, &c, 1);
	}
	else
	{
		write(1, &c, 1);
		while (spaces < flags.length - 1)
		{
			write(1, ft_ternary(flags.prefix == 1, "0", " "), 1);
			spaces++;
		}
	}
	return (ft_ternaryi(flags.length, flags.length, 1));
}
