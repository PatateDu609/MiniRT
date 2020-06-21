/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_meta_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 15:45:10 by gboucett          #+#    #+#             */
/*   Updated: 2020/06/21 12:46:08 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int		ft_read_coord(char **str, t_vector result, char *err, void *to_free)
{
	char	*current;

	current = ft_substr(*str, 0, ft_segment_len(*str));
	if (!ft_check_vector(current, 0, result))
	{
		ft_print_error(err, 0, 1);
		free(current);
		free(to_free);
		return (0);
	}
	free(current);
	*str += ft_segment_len(*str);
	ft_skip_separator(str, " \t");
	return (1);
}

int		ft_read_norm(char **str, t_vector res, char *err, void *tfree)
{
	char	*current;

	current = ft_substr(*str, 0, ft_segment_len(*str));
	if (!ft_check_vector(current, 1, res))
	{
		ft_print_error(err, 0, 1);
		free(current);
		free(tfree);
		return (0);
	}
	free(current);
	*str += ft_segment_len(*str);
	ft_skip_separator(str, " \t");
	return (1);
}

int		ft_read_color(char **str, unsigned int *result, void *to_free)
{
	char	*current;

	current = ft_substr(*str, 0, ft_segment_len(*str));
	if (!ft_check_color(current, result) && to_free)
	{
		ft_print_error("Invalid color", 0, 1);
		free(to_free);
		free(current);
		return (0);
	}
	free(current);
	*str += ft_segment_len(*str);
	ft_skip_separator(str, " \t");
	return (1);
}

int		ft_read_ratio(char **str, double *result, void *to_free)
{
	char	*current;

	current = ft_substr(*str, 0, ft_segment_len(*str));
	if (!ft_check_double(current, result, 1))
	{
		ft_print_error("Invalid light ratio", 0, 1);
		free(to_free);
		free(current);
		return (0);
	}
	free(current);
	*str += ft_segment_len(*str);
	ft_skip_separator(str, " \t");
	return (1);
}
