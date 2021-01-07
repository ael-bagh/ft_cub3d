/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:40:10 by ael-bagh          #+#    #+#             */
/*   Updated: 2020/12/05 19:59:10 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_re(char *line)
{
	char	**par;
	int		cw;

	cw = c_w(line, ' ');
	par = ft_split(line, ' ');
	if (g_width != 0 && g_height != 0)
	{
		ft_putstr("Error\ndouble inclusion\n");
		exit(0);
	}
	if (cw != 3)
	{
		ft_putstr("Error:\nwrong number of parameters in resolution!\n");
		exit(0);
	}
	if (str_is_digits(&par[1][0]) && str_is_digits(&par[2][0]))
		wrong_resolution(atoi(&par[1][0]), atoi(&par[2][0]));
	else
	{
		ft_putstr("Error:\nwrong resolution!");
		exit(0);
	}
	freethenipples(par);
}

void	get_no(char *line)
{
	char	**par;
	char	*str;
	int		re;

	re = 0;
	par = ft_split(line, ' ');
	str = ft_strdup("");
	if (g_no != NULL)
		texture_error(0);
	if (c_w(line, ' ') != 2)
	{
		while (++re < c_w(line, ' '))
		{
			str = ft_strjoin(str, strdup(&par[re][0]));
			if (re != c_w(line, ' ') - 1)
				str = ft_strjoin(str, strdup(" "));
		}
		if ((re = open(str, O_RDONLY) <= 0))
			texture_error(1);
		else
			g_no = ft_strdup(str);
	}
	else
		wrong_file(&par[1][0], 1);
	free_this_shit(str, par);
}

void	get_so(char *line)
{
	char	**par;
	char	*str;
	int		re;

	re = 0;
	par = ft_split(line, ' ');
	str = ft_strdup("");
	if (g_so != NULL)
		texture_error(0);
	if (c_w(line, ' ') != 2)
	{
		while (++re < c_w(line, ' '))
		{
			str = ft_strjoin((str), ft_strdup(&par[re][0]));
			if (re != c_w(line, ' ') - 1)
				str = ft_strjoin((str), ft_strdup(" "));
		}
		if ((re = open(str, O_RDONLY) <= 0))
			texture_error(2);
		else
			g_so = ft_strdup(str);
	}
	else
		wrong_file(&par[1][0], 2);
	free_this_shit(str, par);
}

void	get_we(char *line)
{
	char	**par;
	char	*str;
	int		re;

	re = 0;
	par = ft_split(line, ' ');
	str = ft_strdup("");
	if (g_we != NULL)
		texture_error(0);
	if (c_w(line, ' ') != 2)
	{
		while (++re < c_w(line, ' '))
		{
			str = ft_strjoin(str, strdup(&par[re][0]));
			if (re != c_w(line, ' ') - 1)
				str = ft_strjoin(str, strdup(" "));
		}
		if ((re = open(str, O_RDONLY) <= 0))
			texture_error(3);
		else
			g_we = ft_strdup(str);
	}
	else
		wrong_file(&par[1][0], 3);
	free_this_shit(str, par);
}

void	get_ea(char *line)
{
	char	**par;
	char	*str;
	int		re;

	re = 0;
	par = ft_split(line, ' ');
	str = ft_strdup("");
	if (g_ea != NULL)
		texture_error(0);
	if (c_w(line, ' ') != 2)
	{
		while (++re < c_w(line, ' '))
		{
			str = ft_strjoin(str, strdup(&par[re][0]));
			if (re != c_w(line, ' ') - 1)
				str = ft_strjoin(str, strdup(" "));
		}
		if ((re = open(str, O_RDONLY) <= 0))
			texture_error(4);
		else
			g_ea = ft_strdup(str);
	}
	else
		wrong_file(&par[1][0], 4);
	free_this_shit(str, par);
}
