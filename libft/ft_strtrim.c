/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:47:24 by gboucett          #+#    #+#             */
/*   Updated: 2019/11/11 00:26:45 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_trimedlen(const char *s1, const char *set)
{
	unsigned int	size;
	const char		*s;

	size = ft_strlen(s1);
	s = s1;
	while (*s1 && ft_strchr(set, *s1))
	{
		s1++;
		size--;
	}
	if (!*s1)
		return (0);
	s += ft_strlen(s);
	while (s != (s1 + 1) && ft_strchr(set, *s))
	{
		s--;
		size--;
	}
	return (size + 1);
}

char					*ft_strtrim(const char *s1, const char *set)
{
	unsigned int	size;
	char			*result;
	unsigned int	i;

	if (!s1)
		return (NULL);
	if (!set || !*set)
		return (ft_strdup(s1));
	size = ft_trimedlen(s1, set);
	if (!(result = (char *)malloc(size + 1)))
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = 0;
	while (i < size)
	{
		result[i] = *s1;
		i++;
		s1++;
	}
	result[i] = 0;
	return (result);
}
