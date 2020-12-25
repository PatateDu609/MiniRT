/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboucett <gboucett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:52:24 by gboucett          #+#    #+#             */
/*   Updated: 2020/12/25 13:28:57 by gboucett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read(int fd, char *buffer, char **line)
{
	char	*tmp;
	int		chr_read;
	int		pos;

	chr_read = read(fd, buffer, BUFFER_SIZE);
	while (chr_read > 0)
	{
		buffer[chr_read] = 0;
		tmp = ft_strjoin_sp(*line, buffer);
		free(*line);
		*line = tmp;
		pos = ft_strchr_sp(buffer, '\n');
		if (pos != -1)
		{
			ft_memmove_sp(buffer, buffer + pos, BUFFER_SIZE - pos);
			buffer[BUFFER_SIZE - pos] = 0;
			break ;
		}
		chr_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (chr_read > 0)
		return (1);
	else if (chr_read)
		return (-1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char		buffer[100][BUFFER_SIZE + 1];
	int				pos;

	if (BUFFER_SIZE <= 0 || !line || fd < 0)
		return (-1);
	if (buffer[fd][0])
		*line = ft_strdup_sp(buffer[fd]);
	else
		*line = ft_strdup_sp("");
	if (!*line)
		return (-1);
	if (!(buffer[fd][0]))
		return (ft_read(fd, buffer[fd], line));
	pos = ft_strchr_sp(buffer[fd], '\n');
	if (pos == -1)
		return (ft_read(fd, buffer[fd], line));
	ft_memmove_sp(buffer[fd], buffer[fd] + pos, BUFFER_SIZE - pos);
	return (1);
}
