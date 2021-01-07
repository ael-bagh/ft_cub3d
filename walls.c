/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:09:50 by ael-bagh          #+#    #+#             */
/*   Updated: 2021/01/05 19:07:02 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		init_textures(void)
{
	int		w;
	int		h;

	if (!(g_nt.img))
		if (!(g_nt.img = mlx_xpm_file_to_image(g_vars.mlx, g_no, &w, &h)))
			texture_error(1);
	if (!(g_nt.addr))
		g_nt.addr = mlx_get_data_addr(g_nt.img, &g_nt.bpp, &g_nt.ll, &g_nt.en);
	if (!(g_st.img))
		if (!(g_st.img = mlx_xpm_file_to_image(g_vars.mlx, g_so, &w, &h)))
			texture_error(2);
	if (!(g_st.addr))
		g_st.addr = mlx_get_data_addr(g_st.img, &g_st.bpp, &g_st.ll, &g_st.en);
	if (!(g_wt.img))
		if (!(g_wt.img = mlx_xpm_file_to_image(g_vars.mlx, g_we, &w, &h)))
			texture_error(3);
	if (!(g_wt.addr))
		g_wt.addr = mlx_get_data_addr(g_wt.img, &g_wt.bpp, &g_wt.ll, &g_wt.en);
	if (!(g_et.img))
		if (!(g_et.img = mlx_xpm_file_to_image(g_vars.mlx, g_ea, &w, &h)))
			texture_error(4);
	if (!(g_et.addr))
		g_et.addr = mlx_get_data_addr(g_et.img, &g_et.bpp, &g_et.ll, &g_et.en);
}

void		ray_norm(int i)
{
	g_col.perp_dist = g_rays[i].dist * cos(g_rays[i].angle - g_p.angle);
	g_col.distproj = (g_width / 2) / tan(g_p.fov / 2);
	g_col.projwallh = (g_tile_size / g_col.perp_dist) * g_col.distproj;
	g_col.strip_h = (int)g_col.projwallh;
	g_col.walltop = (g_height / 2) - (g_col.strip_h / 2);
	g_col.walltop = g_col.walltop < 0 ? 0 : g_col.walltop;
	g_col.wallbot = (g_height / 2) + (g_col.strip_h / 2);
	g_col.wallbot = (g_col.wallbot > g_height) ? g_height : g_col.wallbot;
	if (g_rays[i].hit_v)
		g_col.xoff = (int)g_rays[i].hity % g_tile_size;
	else
		g_col.xoff = (int)g_rays[i].hitx % g_tile_size;
}

int			assign_textures(int i)
{
	int		*l9lawi[4];
	int		dst;

	l9lawi[0] = (int*)g_nt.addr;
	l9lawi[1] = (int*)g_st.addr;
	l9lawi[2] = (int*)g_wt.addr;
	l9lawi[3] = (int*)g_et.addr;
	if (g_rays[i].is_up && !g_rays[i].hit_v)
		dst = l9lawi[0][64 * g_col.yoff + g_col.xoff];
	if (g_rays[i].is_left && g_rays[i].hit_v)
		dst = l9lawi[1][64 * g_col.yoff + g_col.xoff];
	if (g_rays[i].is_down && !g_rays[i].hit_v)
		dst = l9lawi[2][64 * g_col.yoff + g_col.xoff];
	if (g_rays[i].is_right && g_rays[i].hit_v)
		dst = l9lawi[3][64 * g_col.yoff + g_col.xoff];
	return (dst);
}

void		generatel9lawi(void)
{
	int		i;
	int		y;

	i = 0;
	init_textures();
	while (i < g_width)
	{
		ray_norm(i);
		y = g_col.walltop;
		while (y < g_col.wallbot)
		{
			g_col.dist = y + (g_col.strip_h / 2) - (g_height / 2);
			g_col.yoff = (int)(g_col.dist * ((float)64 / g_col.strip_h));
			my_mlx_pixel_put(&g_img, i, y, assign_textures(i));
			y++;
		}
		i++;
	}
}

void		floor_ceiling(void)
{
	int i;
	int j;
	int fc;
	int cc;

	i = -1;
	fc = ((g_fr & 0xff) << 16) + ((g_fg & 0xff) << 8) + (g_fb & 0xff);
	cc = ((g_cr & 0xff) << 16) + ((g_cg & 0xff) << 8) + (g_cb & 0xff);
	while (++i < g_height)
	{
		j = -1;
		while (++j < g_width)
		{
			if (i > g_height / 2)
				my_mlx_pixel_put(&g_img, j, i, fc);
			else
				my_mlx_pixel_put(&g_img, j, i, cc);
		}
	}
}
