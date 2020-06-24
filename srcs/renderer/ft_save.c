/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:38:59 by rbourgea          #+#    #+#             */
/*   Updated: 2020/02/11 00:49:55 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_renderer.h"
#include <fcntl.h>

static void		ft_header(unsigned char *header, int width, int height)
{
	int		filesize;

	filesize = 54 + 4 * width * height;
	header[0] = 'B';
	header[1] = 'M';
	header[2] = filesize;
	header[3] = filesize >> 8;
	header[4] = filesize >> 16;
	header[5] = filesize >> 24;
	header[6] = 0;
	header[7] = 0;
	header[8] = 0;
	header[9] = 0;
	header[10] = 54;
	header[11] = 0;
	header[12] = 0;
	header[13] = 0;
}

static void		ft_bmpfileinfo(unsigned char *bmpfileinfo,
		int width, int height)
{
	bmpfileinfo[0] = 40;
	bmpfileinfo[1] = 0;
	bmpfileinfo[2] = 0;
	bmpfileinfo[3] = 0;
	bmpfileinfo[4] = width;
	bmpfileinfo[5] = width >> 8;
	bmpfileinfo[6] = width >> 16;
	bmpfileinfo[7] = width >> 24;
	bmpfileinfo[8] = height;
	bmpfileinfo[9] = height >> 8;
	bmpfileinfo[10] = height >> 16;
	bmpfileinfo[11] = height >> 24;
	bmpfileinfo[12] = 0;
	bmpfileinfo[13] = 0;
	bmpfileinfo[14] = 32;
	bmpfileinfo[15] = 0;
}

static void		ft_write_data(unsigned int *data, int width, int height,
		int fd)
{
	int		i;
	int		j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
			write(fd, data + (i * width + j++), 4);
		i++;
	}
}

void			ft_save(unsigned int *data, int width, int height)
{
	int				fd;
	unsigned char	header[14];
	unsigned char	bmpfileinfo[40];

	if ((fd = open("minirt.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1)
		return ;
	ft_memset(header, 0, 14);
	ft_memset(bmpfileinfo, 0, 40);
	ft_header(header, width, height);
	ft_bmpfileinfo(bmpfileinfo, width, height);
	write(fd, header, 14);
	write(fd, bmpfileinfo, 40);
	ft_write_data(data, width, height, fd);
	close(fd);
}
