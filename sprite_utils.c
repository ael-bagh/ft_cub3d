/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 17:17:59 by ael-bagh          #+#    #+#             */
/*   Updated: 2021/01/05 17:18:31 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			has_sprite(float x, float y)
{
	int ughx;
	int ughy;

	if (x < 0 || x > (g_mapw * g_tile_size) ||
		y < 0 || y > (g_maph * g_tile_size))
		return (1);
	ughx = floor(x / g_tile_size);
	ughy = floor(y / g_tile_size);
	if (g_map_finished[ughy][ughx] == '2')
		return (1);
	else
		return (0);
}
