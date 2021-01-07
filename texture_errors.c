/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 22:08:28 by ael-bagh          #+#    #+#             */
/*   Updated: 2021/01/05 19:12:14 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	texture_error(int error)
{
	if (error == 0)
		ft_putstr("Error\ndouble inclusion\n");
	else if (error == 1)
		ft_putstr("Error:\ninvalid north texture!\n");
	else if (error == 2)
		ft_putstr("Error:\ninvalid south texture!\n");
	else if (error == 3)
		ft_putstr("Error:\ninvalid west texture!\n");
	else if (error == 4)
		ft_putstr("Error:\ninvalid east texture!\n");
	else if (error == 5)
		ft_putstr("Error:\ninvalid sprite texture!\n");
	exit(0);
}

void	free_this_shit(char *str, char **s)
{
	free(str);
	freethenipples(s);
}

void	wrong_file(char *file, int type)
{
	int re;

	if ((re = open(file, O_RDONLY) > 0) && type == 1)
		g_no = ft_strdup(file);
	else if ((re = open(file, O_RDONLY) <= 0) && type == 1)
		texture_error(1);
	if ((re = open(file, O_RDONLY) > 0) && type == 2)
		g_so = ft_strdup(file);
	else if ((re = open(file, O_RDONLY) <= 0) && type == 2)
		texture_error(2);
	if ((re = open(file, O_RDONLY) > 0) && type == 3)
		g_we = ft_strdup(file);
	else if ((re = open(file, O_RDONLY) <= 0) && type == 3)
		texture_error(3);
	if ((re = open(file, O_RDONLY) > 0) && type == 4)
		g_ea = ft_strdup(file);
	else if ((re = open(file, O_RDONLY) <= 0) && type == 4)
		texture_error(4);
	if ((re = open(file, O_RDONLY) > 0) && type == 5)
		g_s = ft_strdup(file);
	else if ((re = open(file, O_RDONLY) <= 0) && type == 5)
		texture_error(5);
}
