/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:03:14 by ael-bagh          #+#    #+#             */
/*   Updated: 2021/01/05 12:59:59 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		surrend_by_spaces(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (j < g_mapw + 2)
			j++;
		map[i][j] = '\0';
		i++;
		j = 0;
	}
	i = -1;
	while (++i < g_maph + 2 && (j = -1))
		while (++j < g_mapw + 2)
		{
			map[i][j] = ' ';
		}
}

void		fill_map(char **map)
{
	int i;
	int j;
	int x;
	int y;

	i = 1;
	j = 1;
	x = 0;
	y = 0;
	while (x < g_maph)
	{
		while (y < g_mapw)
		{
			if (y < ft_strlen(g_map_array[x]))
				map[i][j] = g_map_array[x][y];
			else
				map[i][j] = ' ';
			y++;
			j++;
		}
		i++;
		x++;
		j = 1;
		y = 0;
	}
}

void		longuest_line(void)
{
	int i;
	int j;
	int max;

	i = 0;
	j = 0;
	max = 0;
	while (g_map_array[i])
	{
		while (g_map_array[i][j] != '\0')
			j++;
		i++;
		if (j > max)
			max = j;
		j = 0;
	}
	g_mapw = max;
}

void		sedat_madame(char **map)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
		}
	}
}

int			check_map(int to_check, char c)
{
	if (to_check == 0)
	{
		if (c != '1' && c != '0' && c != '2'
		&& c != 'N' && c != 'W' && c != 'E'
		&& c != 'S' && c != ' ')
			return (1);
		return (0);
	}
	return (0);
}
