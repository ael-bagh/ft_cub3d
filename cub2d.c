/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:37:03 by ael-bagh          #+#    #+#             */
/*   Updated: 2021/01/06 18:52:11 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		update(void)
{
	float	newx;
	float	newy;
	float	move_step;

	g_p.angle += g_p.turn * g_p.rspeed;
	move_step = g_p.walk * g_p.speed;
	newx = g_p.x + cos(g_p.angle) * move_step;
	newy = g_p.y + sin(g_p.angle) * move_step;
	if (!has_wall(g_p.x, newy) && !has_sprite(g_p.x, newy))
		g_p.y = newy;
	if (!has_wall(newx, g_p.y) && !has_sprite(newx, g_p.y))
		g_p.x = newx;
}

void		render(void)
{
	update();
	draw_map();
	cast_rays();
	floor_ceiling();
	generatel9lawi();
	to_sprite();
	mlx_put_image_to_window(g_vars.mlx, g_vars.win, g_img.img, 0, 0);
	if (g_save == 1)
		save_bmp();
	mlx_destroy_image(g_vars.mlx, g_img.img);
}

int			key_press(int keycode)
{
	if (keycode == 13)
		g_p.walk = 1;
	if (keycode == 1)
		g_p.walk = -1;
	if (keycode == 0)
		g_p.turn = -1;
	if (keycode == 2)
		g_p.turn = 1;
	if (keycode == 53)
	{
		free(g_sp);
		freethenipples(g_map_finished);
		exit(0);
	}
	return (0);
}

int			key_release(int keycode)
{
	if (keycode == 13)
		g_p.walk = 0;
	if (keycode == 1)
		g_p.walk = 0;
	if (keycode == 0)
		g_p.turn = 0;
	if (keycode == 2)
		g_p.turn = 0;
	return (0);
}

int			move(void)
{
	mlx_hook(g_vars.win, 2, 0, key_press, &g_vars);
	render();
	mlx_hook(g_vars.win, 3, 0, key_release, &g_vars);
	mlx_hook(g_vars.win, 17, 0, ft_quit, &g_vars);
	return (0);
}
