/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:12:17 by gboucett          #+#    #+#             */
/*   Updated: 2020/12/23 17:17:14 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/*
**	F_*			: defines about flags' values
**	F_ZERO		: there is some zeroes as prefix
**	F_SPACE		: there is a space as prefix
**	F_ZERO_SIZE	: there is both zeros and space as prefix
**	F_RIGHT		: data is aligned to right
**	F_LEFT		: data is aligned to left
**	F_DEF_PREC	: default precision
*/
# define F_DEF_PREC		-1
# define F_NO_PREFIX	0
# define F_ZERO			1
# define F_SPACE		2
# define F_ZERO_SPACE	3
# define F_RIGHT		4
# define F_LEFT			5

/*
**	W_*				: defines about waiting states
**	W_NOTHING		: wating for nothing
**	W_LENGTH		: waiting for the length of data
**	W_PRECISION		: waiting for the precision
**	W_POINT			: waiting for the point that annouces precision
**					(to avoid %**d being misunderstood)
**	W_FIRST_FLAG	: waiting for members of the first flag
*/
# define W_NOTHING		0
# define W_LENGTH		1
# define W_PRECISION	2
# define W_POINT		3
# define W_FIRST_FLAG	4

/*
**	alignment	: right (0) or left (1)
**	length		: minimal length displayed (never truncate output)
**	length_def	: is flags::length at it's default value (1) or not (0)
**	precision	: precision on display (min or max caracter displayed)
**	prefix		: is there any prefix (zero(1) or space(2) or both(3)) ?
**	conversion	: conversion type (s, c, d, i, u, X, x, p, %)
*/
typedef struct s_flags
{
	int		alignment;
	int		length;
	int		length_def;
	int		precision;
	int		prefix;
	char	conversion;
}	t_flags;

int		ft_putchar(char c, t_flags flags);
int		ft_putstrr(const char *str, t_flags flags);
void	ft_putunsigned(unsigned int n, int *size, t_flags flags);
int		ft_putnbr(int n, t_flags flags);
void	ft_puthexa(int mode, unsigned long n, int *size, t_flags flags);
int		ft_putptr(void *ptr, t_flags flags);

void	ft_print_nbr(unsigned int n);
int		ft_size_base(long long n, size_t size, int base);
void	ft_print_prefix(t_flags flags, int len);
void	ft_print_zeroes(int len, int precision);
int		ft_size_prefix(t_flags flags, int len);

int		ft_isformat_or_flag(char c);
int		ft_isformat(char c);
int		ft_isflag(char c);

void	ft_flag_numbers(t_flags *flags, const char **str, int *waiting);
void	ft_prefix(t_flags *flags, char current);
void	ft_alignment(t_flags *flags);
void	ft_star(t_flags *flags, int *waiting, va_list args);
t_flags	ft_parse(const char **str, va_list args);
void	ft_update_flags(t_flags *flags, int waiting);

int		ft_printf(const char *str, ...);

#endif
