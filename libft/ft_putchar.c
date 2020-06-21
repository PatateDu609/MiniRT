/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:34:27 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/30 19:27:07 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c, t_flags flags)
{
	int		spaces;
	char	*disp;

	spaces = 0;
	disp = (flags.prefix == F_ZERO || flags.prefix == F_ZERO_SPACE) ? "0" : " ";
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
			write(1, (flags.prefix == 1) ? "0" : " ", 1);
			spaces++;
		}
	}
	return (flags.length ? flags.length : 1);
}
