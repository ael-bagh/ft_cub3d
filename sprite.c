/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:13:45 by ael-bagh          #+#    #+#             */
/*   Updated: 2021/01/18 18:02:42 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

float	deg(float x)
{
	return ((180 / M_PI) * x);
}

void	init_sprite(void)
{
	int i;
	int j;
	int k;
	int w;
	int h;

	k = 0;
	i = -1;
	g_sp = malloc(sizeof(t_sprite) * (g_s_count + 1));
	if (!(g_si.img = mlx_xpm_file_to_image(g_vars.mlx, g_s, &w, &h)))
		texture_error(5);
	g_si.addr = mlx_get_data_addr(g_si.img, &g_si.bpp, &g_si.ll, &g_si.en);
	while (g_map_finished[++i] && (j = -1) && (k < g_s_count))
	{
		while (g_map_finished[i][++j] && (k < g_s_count))
			if (g_map_finished[i][j] == '2')
			{
				g_sp[k].x = (float)((j + 0.5) * 64);
				g_sp[k].y = (float)((i + 0.5) * 64);
				g_sp[k].dist = sqrtf(((g_sp[k].x) - g_p.x) * ((g_sp[k].x)
					- g_p.x) + ((g_sp[k].y) - g_p.y) * ((g_sp[k].y) - g_p.y));
				k++;
			}
	}
}

void	to_sort(void)
{
	int				i;
	int				j;
	t_sprite		tmp;

	i = 0;
	while (i < g_s_count - 1)
	{
		j = i;
		while (j < g_s_count - 1)
		{
			if (g_sp[j].dist < g_sp[j + 1].dist)
			{
				tmp = g_sp[j];
				g_sp[j] = g_sp[j + 1];
				g_sp[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	to_sprite(void)
{
	float	angle;
	int		k;

	k = -1;
	to_sort();
	angle = 0;
	while (++k < g_s_count)
	{
		g_sp[k].dist = sqrtf(((g_sp[k].x) - g_p.x) * ((g_sp[k].x)
					- g_p.x) + ((g_sp[k].y) - g_p.y) * ((g_sp[k].y) - g_p.y));
		angle = atan2f(g_sp[k].y - g_p.y, g_sp[k].x - g_p.x);
		while (angle - g_p.angle > M_PI)
			angle -= 2 * M_PI;
		while (angle - g_p.angle < -M_PI)
			angle += 2 * M_PI;
		g_sp[k].size = (float)((g_width / g_sp[k].dist) * 64);
		g_sp[k].yof = (float)(g_height / 2 - g_sp[k].size / 2);
		g_sp[k].xof = (float)(((deg(angle) - deg(g_p.angle)) * g_width)
		/ 64 + ((g_width / 2) - (int)g_sp[k].size / 2));
		draw_sprite(k);
	}
}

void	draw_sprite(int id)
{
	int		i;
	int		j;
	int		c;
	int		*l9alwa;
	float	size;

	i = -1;
	size = g_sp[id].size;
	l9alwa = (int*)g_si.addr;
	while (++i < size - 1 && (j = -1))
	{
		if (g_sp[id].xof + i <= 0 || g_sp[id].xof + i > g_width - 1)
			continue ;
		if (g_rays[(int)(g_sp[id].xof + i)].dist <= g_sp[id].dist)
			continue ;
		while (++j < size - 1)
		{
			if (g_sp[id].yof + j <= 0 || g_sp[id].yof + j > g_height - 1)
				continue ;
			c = l9alwa[(int)((64) *
					(64 * j / (int)size) + (64 * i / (int)size))];
			if (c != l9alwa[0])
				my_mlx_pixel_put(&g_img, i + g_sp[id].xof, j + g_sp[id].yof, c);
		}
	}
}
