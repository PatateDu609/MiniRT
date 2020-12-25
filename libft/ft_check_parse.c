/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:20:51 by gboucett          #+#    #+#             */
/*   Updated: 2020/12/23 17:45:00 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isformat_or_flag(char c)
{
	return (ft_isformat(c) || ft_isflag(c));
}

int	ft_isformat(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int	ft_isflag(char c)
{
	return (c == '.' || c == '-' || c == '*' || c == ' ' || ft_isdigit(c));
}
