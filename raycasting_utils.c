/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycating_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:42:15 by ael-bagh          #+#    #+#             */
/*   Updated: 2021/01/05 17:19:17 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

float		normalangle(float rayangle)
{
	rayangle = remainder(rayangle, (2 * M_PI));
	if (rayangle < 0)
		rayangle = (2 * M_PI) + rayangle;
	return (rayangle);
}

void		vert_ray(float angle)
{
	g_r.xstep = g_tile_size;
	g_r.xstep *= g_is_left ? -1 : 1;
	g_r.ystep = g_tile_size * tan(angle);
	g_r.ystep *= (g_is_up && g_r.ystep > 0) ? -1 : 1;
	g_r.ystep *= (g_is_down && g_r.ystep < 0) ? -1 : 1;
	g_r.nvx = g_r.x_intercept;
	g_r.nvy = g_r.y_intercept;
	while (g_r.nvx >= 0 && g_r.nvx <= g_mapw * 64 &&
			g_r.nvy >= 0 && g_r.nvy <= g_maph * 64)
	{
		g_r.xcheck = g_r.nvx + (g_is_left ? -1 : 0);
		g_r.ycheck = g_r.nvy;
		if (has_wall(g_r.xcheck, g_r.ycheck))
		{
			g_r.vert_hitx = g_r.nvx;
			g_r.vert_hity = g_r.nvy;
			g_r.found_verthit = 1;
			break ;
		}
		else
		{
			g_r.nvx += g_r.xstep;
			g_r.nvy += g_r.ystep;
		}
	}
}

void		horz_ray(float angle)
{
	g_r.ystep = g_tile_size;
	g_r.ystep *= g_is_up ? -1 : 1;
	g_r.xstep = g_tile_size / tan(angle);
	g_r.xstep *= (g_is_left && g_r.xstep > 0) ? -1 : 1;
	g_r.xstep *= (g_is_right && g_r.xstep < 0) ? -1 : 1;
	g_r.nhx = g_r.x_intercept;
	g_r.nhy = g_r.y_intercept;
	while (g_r.nhx >= 0 && g_r.nhx <= g_mapw * 64 &&
		g_r.nhy >= 0 && g_r.nhy <= g_maph * 64)
	{
		g_r.xcheck = g_r.nhx;
		g_r.ycheck = g_r.nhy + (g_is_up ? -1 : 0);
		if (has_wall(g_r.xcheck, g_r.ycheck))
		{
			g_r.horz_hitx = g_r.nhx;
			g_r.horz_hity = g_r.nhy;
			g_r.found_horzhit = 1;
			break ;
		}
		else
		{
			g_r.nhx += g_r.xstep;
			g_r.nhy += g_r.ystep;
		}
	}
}

void		push_ray(int strip_id)
{
	if (g_r.found_horzhit)
		g_r.hdist = dist_pts(g_p.x, g_p.y, g_r.horz_hitx, g_r.horz_hity);
	else
		g_r.hdist = FLT_MAX;
	if (g_r.found_verthit)
		g_r.vdist = dist_pts(g_p.x, g_p.y, g_r.vert_hitx, g_r.vert_hity);
	else
		g_r.vdist = FLT_MAX;
	if (g_r.vdist < g_r.hdist)
	{
		g_rays[strip_id].dist = g_r.vdist;
		g_rays[strip_id].hitx = g_r.vert_hitx;
		g_rays[strip_id].hity = g_r.vert_hity;
		g_rays[strip_id].hit_v = 1;
	}
	else
	{
		g_rays[strip_id].dist = g_r.hdist;
		g_rays[strip_id].hitx = g_r.horz_hitx;
		g_rays[strip_id].hity = g_r.horz_hity;
		g_rays[strip_id].hit_v = 0;
	}
}
