/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:04:45 by ael-bagh          #+#    #+#             */
/*   Updated: 2021/01/05 17:23:26 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!((x < 0 && x > g_height) && (y < 0 && y > g_width)))
	{
		dst = data->addr + (y * data->ll + x
			* (data->bpp / 8));
		*(unsigned int*)dst = color;
	}
}

void		draw_map(void)
{
	g_img.img = mlx_new_image(g_vars.mlx, g_width, g_height);
	g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bpp,
					&g_img.ll, &g_img.en);
}

int			has_wall(float x, float y)
{
	int ughx;
	int ughy;

	if (x < 0 || x > (g_mapw * g_tile_size) ||
		y < 0 || y > (g_maph * g_tile_size))
		return (1);
	ughx = floor(x / g_tile_size);
	ughy = floor(y / g_tile_size);
	if (g_map_finished[ughy][ughx] == '1')
		return (1);
	else
		return (0);
}

int			ft_quit(void)
{
	key_press(53);
	return (0);
}
