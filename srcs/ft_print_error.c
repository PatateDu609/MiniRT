/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 10:45:53 by rbourgea          #+#    #+#             */
/*   Updated: 2019/12/22 17:19:15 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_print_error(char *str, int sys, int should_exit)
{
	if (sys)
		printf("Error %s: %s\n", g_program_name, strerror(errno));
	else
		printf("Error %s: %s\n", g_program_name, str);
	if (should_exit)
		exit(1);
}
