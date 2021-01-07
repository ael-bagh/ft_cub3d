/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:16:53 by ael-bagh          #+#    #+#             */
/*   Updated: 2021/01/05 19:16:48 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

float		dist_pts(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void		cast_ray(int strip_id, float angle)
{
	angle = normalangle(angle);
	g_is_down = angle > 0 && angle < M_PI;
	g_is_up = !g_is_down;
	g_is_right = angle < (M_PI_2) || angle > (1.5 * M_PI);
	g_is_left = !g_is_right;
	g_r.found_horzhit = 0;
	g_r.horz_hitx = 0;
	g_r.horz_hity = 0;
	g_r.y_intercept = floor(g_p.y / g_tile_size) * g_tile_size;
	g_r.y_intercept += g_is_down ? g_tile_size : 0;
	g_r.x_intercept = g_p.x + (g_r.y_intercept - g_p.y) / tan(angle);
	horz_ray(angle);
	g_r.found_verthit = 0;
	g_r.vert_hitx = 0;
	g_r.vert_hity = 0;
	g_r.x_intercept = floor(g_p.x / g_tile_size) * g_tile_size;
	g_r.x_intercept += g_is_right ? g_tile_size : 0;
	g_r.y_intercept = g_p.y + (g_r.x_intercept - g_p.x) * tan(angle);
	vert_ray(angle);
	push_ray(strip_id);
	g_rays[strip_id].angle = angle;
	g_rays[strip_id].is_down = g_is_down;
	g_rays[strip_id].is_up = g_is_up;
	g_rays[strip_id].is_right = g_is_right;
	g_rays[strip_id].is_left = g_is_left;
}

void		cast_rays(void)
{
	float	ray_angle;
	int		strip_id;

	strip_id = 0;
	ray_angle = g_p.angle - (g_p.fov / 2);
	while (strip_id < g_width)
	{
		cast_ray(strip_id, ray_angle);
		ray_angle += g_p.fov / g_width;
		strip_id++;
	}
}
