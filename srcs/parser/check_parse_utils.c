/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:51:00 by rbourgea          #+#    #+#             */
/*   Updated: 2019/12/20 10:27:06 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int			ft_splitted_len(char **strs)
{
	int		result;

	result = 0;
	while (*strs++ != NULL)
		result++;
	return (result);
}

void		ft_splitted_clear(char **strs)
{
	char **temp;

	temp = strs;
	while (*strs)
	{
		free(*strs);
		strs++;
	}
	free(temp);
}

int			ft_special_strchr(char *str, char *set)
{
	if (str == NULL)
		return (0);
	if (set == NULL)
		return (0);
	while (*str)
		if (!ft_strchr(set, *str++))
			return (0);
	return (1);
}

double		ft_strtof(char *str)
{
	double	result;
	double	fract;

	result = ft_atoi(str);
	while (*str && *str != '.')
		str++;
	if (*str != '.')
		return (result);
	str++;
	fract = ft_atoi(str);
	fract /= pow(10., ft_strlen(str));
	result += fract;
	return (result);
}

void		ft_skip_separator(char **str, char *separator)
{
	while (**str && ft_strchr(separator, **str))
		*str += 1;
}
