/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:55:17 by gboucett          #+#    #+#             */
/*   Updated: 2020/12/24 21:49:16 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr, t_flags flags)
{
	unsigned long	p;
	int				result;
	int				spaces;
	int				size;

	p = (unsigned long)ptr;
	size = ft_size_base(p, 2, 16) + ft_ternaryi(!p, 1, 0);
	if (flags.alignment == F_RIGHT)
	{
		spaces = ft_size_prefix(flags, size);
		ft_print_prefix(flags, size);
		flags.length = 1;
	}
	else if (flags.alignment == F_LEFT && flags.length >= 2)
		flags.length -= 2;
	ft_putstr_fd("0x", 1);
	ft_puthexa(1, p, &result, flags);
	if (flags.alignment == F_RIGHT)
		result += spaces;
	return (result + 2);
}
