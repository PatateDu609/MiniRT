/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_structs_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 14:02:52 by gboucett          #+#    #+#             */
/*   Updated: 2020/06/19 22:13:31 by gboucett         ###   ########.fr       */
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
	ft_printf("width = %d\n", resolution->width);
	ft_printf("height = %d\n", resolution->height);
}
