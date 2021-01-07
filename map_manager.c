/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:46:48 by ael-bagh          #+#    #+#             */
/*   Updated: 2021/01/05 12:59:59 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		player_init(char c, int x, int y)
{
	if (g_peeinit == 1)
	{
		ft_putstr("Error:\nthe map has more than one player\n");
		exit(0);
	}
	else
	{
		g_tile_size = 64;
		g_p.x = (x * g_tile_size) + (g_tile_size / 2);
		g_p.y = (y * g_tile_size) + (g_tile_size / 2);
		g_peeinit = 1;
		if (c == 'N')
			g_p.angle = 270 * (M_PI / 180);
		else if (c == 'S')
			g_p.angle = 90 * (M_PI / 180);
		else if (c == 'E')
			g_p.angle = 0;
		else if (c == 'W')
			g_p.angle = M_PI;
		g_p.fov = 60 * (M_PI / 180);
		g_p.turn = 0;
		g_p.walk = 0;
		g_p.speed = 8;
		g_p.rspeed = 4 * (M_PI / 180);
	}
}

void		array_height(void)
{
	int i;

	i = 0;
	while (g_map_array[i])
		i++;
	g_maph = i;
}

void		map_manager(void)
{
	char	**map_array;
	int		i;
	int		j;

	j = 0;
	i = 0;
	map_array = (char**)malloc((g_maph + 3) * sizeof(char*));
	while (i < g_maph + 2)
	{
		map_array[i] = (char*)malloc((g_mapw + 3) * sizeof(char));
		i++;
	}
	map_array[i] = NULL;
	surrend_by_spaces(map_array);
	fill_map(map_array);
	map_closed(map_array);
	sedat_madame(map_array);
	g_map_finished = map_array;
}

void		map_closed(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	g_s_count = 0;
	while (++i <= g_maph)
	{
		while (++j <= g_mapw)
		{
			g_s_count += map[i][j] == '2';
			if (check_map(0, map[i][j]))
				error_redirect(0);
			if (map[i][j] != ' ' && map[i][j] != '1')
			{
				if (map[i][j + 1] == ' ' || map[i][j - 1] == ' '
				|| map[i + 1][j] == ' ' || map[i - 1][j] == ' ')
					error_redirect(1);
				if ((map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'E' || map[i][j] == 'W'))
					player_init(map[i][j], j, i);
			}
		}
		j = 0;
	}
}

void		error_redirect(int error)
{
	if (error == 0)
		ft_putstr("Error:\nmap has an unknown character\n");
	else if (error == 1)
		ft_putstr("Error:\nthe map isnt closed");
	else if (error == 2)
		ft_putstr("Error:\nmap doesnt exist.");
	else if (error == 3)
		ft_putstr("Error:\nplayer doesnt exist.");
	exit(0);
}
