/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_structs_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:02:52 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/19 22:13:31 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	ft_print_resolution(t_element *element)
{
	t_resolution *resolution;

	if (!element->content)
	{
		printf("Invalid resolution\n");
		return ;
	}
	resolution = (t_resolution *)element->content;
	printf("width = %d\n", resolution->width);
	printf("height = %d\n", resolution->height);
}
