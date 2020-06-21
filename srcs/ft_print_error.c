/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 10:45:53 by gboucett          #+#    #+#             */
/*   Updated: 2019/12/22 17:19:15 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_parser.h"

void	ft_print_error(char *str, int sys, int should_exit)
{
	if (sys)
		ft_printf("Error %s: %s\n", g_program_name, strerror(errno));
	else
		ft_printf("Error %s: %s\n", g_program_name, str);
	if (should_exit)
		exit(1);
}
