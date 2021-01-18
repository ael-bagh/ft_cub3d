/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:27:14 by ael-bagh          #+#    #+#             */
/*   Updated: 2021/01/17 15:49:13 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	arguments_errors(int error)
{
	if (error == 1)
		ft_putstr("Error:\nwrong config file extension");
	if (error == 2)
		ft_putstr("Error:\nthe second argument must be --save");
	if (error == 3)
		ft_putstr("Error:\nwrong number of parameters");
	if (error == 4)
		ft_putstr("Error:\nwrong config file");
	exit(0);
}

void	arguments(int argc, char *argv[])
{
	int end;

	end = ft_strlen(argv[1]) - 1;
	if (argc == 3)
	{
		if (argv[1][end] == 'b' && argv[1][end - 1] == 'u' &&
			argv[1][end - 2] == 'c' && argv[1][end - 3] == '.')
			g_file = ft_strdup(argv[1]);
		else
			arguments_errors(1);
		if (!ft_strncmp(argv[2], "--save", 7))
			g_save = 1;
		else
			arguments_errors(2);
	}
	else if (argc == 2)
	{
		if (argv[1][end] == 'b' && argv[1][end - 1] == 'u' &&
			argv[1][end - 2] == 'c' && argv[1][end - 3] == '.')
			g_file = ft_strdup(argv[1]);
		else
			arguments_errors(1);
	}
	else
		arguments_errors(3);
}

int		readline(void)
{
	int		fd;
	int		ret;
	char	*line;

	if ((fd = open(g_file, O_RDONLY)) < 0)
		arguments_errors(4);
	global_init();
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (!all_params())
		{
			if (*line != '\0')
				routing(line);
		}
		else
			routing(line);
		if (ret == 0)
			break ;
		free(line);
	}
	free(line);
	return (0);
}

void	routing(char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		get_re(line);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		get_no(line);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		get_so(line);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		get_we(line);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		get_ea(line);
	else if (line[0] == 'S' && line[1] == ' ')
		get_s(line);
	else if (line[0] == 'F' && line[1] == ' ')
		get_f(line);
	else if (line[0] == 'C' && line[1] == ' ')
		get_c(line);
	else if (all_params())
		readmap(line);
	else
	{
		ft_putstr("one or many parametres format is wrong or missing!\n");
		exit(0);
	}
}

int		main(int argc, char *argv[])
{
	g_save = 0;
	arguments(argc, argv);
	readline();
	manage_map();
	longuest_line();
	array_height();
	if (g_maph == 0 && g_mapw == 0)
		error_redirect(2);
	map_manager();
	if (g_p.x == 0 && g_p.y == 0)
		error_redirect(3);
	free(g_map);
	g_vars.mlx = mlx_init();
	g_vars.win = mlx_new_window(g_vars.mlx, g_width, g_height, "Bismilah!");
	init_sprite();
	if (g_save == 1)
	{
		render();
		save_bmp();
		ft_quit();
	}
	mlx_loop_hook(g_vars.mlx, move, 0);
	mlx_loop(g_vars.mlx);
}
