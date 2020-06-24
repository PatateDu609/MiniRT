/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrows_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:16:53 by rbourgea          #+#    #+#             */
/*   Updated: 2020/06/20 21:00:07 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_window.h"

int			ft_identify_arrows(int keycode)
{
	printf("keycode : %d\n", keycode);
	if (keycode == KEY_DOWN_ARROW)
		return (1);
	else if (keycode == KEY_RIGHT_ARROW)
		return (2);
	else if (keycode == KEY_UP_ARROW)
		return (3);
	else if (keycode == KEY_LEFT_ARROW)
		return (4);
	else if (keycode == KEY_COMMA)
		return (5);
	else if (keycode == KEY_POINT)
		return (6);
	else
		return (0);
}
