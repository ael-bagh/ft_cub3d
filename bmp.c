/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:58:07 by ael-bagh          #+#    #+#             */
/*   Updated: 2021/01/17 15:03:05 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_bzero(void *s, size_t n)
{
	unsigned int i;

	i = 0;
	if (n)
	{
		while (i < n)
		{
			*(unsigned char*)s = 0;
			s++;
			i++;
		}
	}
}

void		header_init(void)
{
	g_bmp.type[0] = 0x42;
	g_bmp.type[1] = 0x4D;
	g_bmp.filesize = (g_width * g_height * 4) + 54;
	g_bmp.reserved1 = 0x00000000;
	g_bmp.reserved2 = 0x00000000;
	g_bmp.pxdataoff = 0x36;
	g_bmp.headersize = 40;
	g_bmp.width = g_width;
	g_bmp.height = g_height * -1;
	g_bmp.planes = 1;
	g_bmp.bpp = 32;
	g_bmp.compression = 0;
	g_bmp.imagesize = g_width * g_height * 4;
	g_bmp.xpermeter = 2835;
	g_bmp.ypermeter = 2835;
	g_bmp.totalcolors = 0;
	g_bmp.importantcolors = 0;
}

void		header_write(int fd)
{
	int			r;

	r = 0;
	r = write(fd, &g_bmp.type, 2);
	r = write(fd, &g_bmp.filesize, 4);
	r = write(fd, &g_bmp.reserved1, 2);
	r = write(fd, &g_bmp.reserved2, 2);
	r = write(fd, &g_bmp.pxdataoff, 4);
	r = write(fd, &g_bmp.headersize, 4);
	r = write(fd, &g_bmp.width, 4);
	r = write(fd, &g_bmp.height, 4);
	r = write(fd, &g_bmp.planes, 2);
	r = write(fd, &g_bmp.bpp, 2);
	r = write(fd, &g_bmp.compression, 4);
	r = write(fd, &g_bmp.imagesize, 4);
	r = write(fd, &g_bmp.xpermeter, 4);
	r = write(fd, &g_bmp.ypermeter, 4);
	r = write(fd, &g_bmp.totalcolors, 4);
	r = write(fd, &g_bmp.importantcolors, 4);
	(void)r;
}

void		write_colors(int fd)
{
	char	*colors;
	int		i;
	int		j;
	int		*color;

	i = 0;
	j = 0;
	color = (int*)g_img.addr;
	if (!(colors = malloc(g_bmp.imagesize * sizeof(char))))
	{
		ft_putstr("Error:\nscreenshot issue");
		exit(0);
	}
	while (i < (int)(g_bmp.imagesize / 4))
	{
		colors[j++] = color[i] & 255;
		colors[j++] = (color[i] & 255 << 8) >> 8;
		colors[j++] = (color[i] & 255 << 16) >> 16;
		colors[j++] = 0;
		i++;
	}
	j = write(fd, colors, g_bmp.imagesize);
	free(colors);
}

void		save_bmp(void)
{
	int		fd;

	if (!((fd = open("screenshot.bmp", O_WRONLY | O_CREAT |
	O_TRUNC, S_IRUSR | S_IWUSR)) > 0))
	{
		ft_putstr("Error:\nscreenshot problem");
		exit(0);
	}
	ft_bzero(&g_bmp, sizeof(t_bmp_file));
	header_init();
	header_write(fd);
	write_colors(fd);
	close(fd);
	(void)g_bmp;
}
