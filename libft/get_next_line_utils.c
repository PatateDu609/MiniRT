/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:52:29 by gboucett          #+#    #+#             */
/*   Updated: 2020/12/24 22:31:19 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove_sp(void *dst, const void *src, size_t len)
{
	char	*srcc;
	char	*dstc;
	size_t	i;

	i = -1;
	srcc = (char *)src;
	dstc = (char *)dst;
	if (srcc < dstc)
		while ((int)(--len) >= 0)
			*(dstc + len) = *(srcc + len);
	else
		while (++i < len)
			*(dstc + i) = *(srcc + i);
	return (dst);
}

static size_t	ft_strlen_sp(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

char	*ft_strdup_sp(const char *s1)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(char) * (ft_strlen_sp(s1) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i++ < ft_strlen_sp(s1))
		result[i - 1] = s1[i - 1];
	result[i - 1] = 0;
	return (result);
}

char	*ft_strjoin_sp(const char *s1, const char *s2)
{
	size_t	size;
	char	*result;
	char	*s;

	size = 0;
	if (s1)
		size += ft_strlen_sp(s1);
	if (s2)
		size += ft_strlen_sp(s2);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	s = result;
	if (s1)
		while (*s1)
			*s++ = *s1++;
	if (s2)
		while (*s2 && *s2 != '\n')
			*s++ = *s2++;
	*s = 0;
	return (result);
}

int	ft_strchr_sp(char *buffer, char chr)
{
	int		pos;

	pos = 0;
	while (buffer[pos] && buffer[pos] != chr)
		pos++;
	if (buffer[pos] == chr)
		return (pos + 1);
	return (-1);
}
