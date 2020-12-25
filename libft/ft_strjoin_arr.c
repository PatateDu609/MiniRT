/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 12:31:24 by gboucett          #+#    #+#             */
/*   Updated: 2020/10/09 23:24:02 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_arr(char **arr, char sep)
{
	char	*result;
	char	*tmp;
	char	str_sep[2];

	if (!arr || !*arr)
		return (0);
	result = ft_strdup(arr[0]);
	arr++;
	str_sep[0] = sep;
	str_sep[1] = 0;
	while (*arr)
	{
		tmp = result;
		result = ft_strjoin(result, str_sep);
		free(tmp);
		tmp = result;
		result = ft_strjoin(result, *arr);
		free(tmp);
		arr++;
	}
	return (result);
}
