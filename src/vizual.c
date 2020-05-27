/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <bglinda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:20:25 by bglinda           #+#    #+#             */
/*   Updated: 2020/05/24 17:21:30 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			define_xo(char *line, t_bonus *viz)
{
	if (*line == '.')
		printw("🔲 ");
	else if (*line == 'O')
	{
		printw("💊 ");
		(viz->o_score)++;
	}
	else if (*line == 'o')
	{
		printw_color("💊 ", 1);
		(viz->o_score)++;
	}
	else if (*line == 'X')
	{
		printw("👑 ");
		(viz->x_score)++;
	}
	else if (*line == 'x')
	{
		printw_color("👑 ", 2);
		(viz->x_score)++;
	}
}

void			print_map(int ver_size, int hor_size, t_bonus *viz)
{
	char		*line;
	int			i;
	int			j;

	i = 0;
	viz->x_score = 0;
	viz->o_score = 0;
	move(23, SHIFT + 1);
	while (i < ver_size)
	{
		j = 0;
		get_next_line(0, &line);
		while (j < hor_size)
		{
			define_xo(&(line[j + 4]), viz);
			j++;
		}
		free(line);
		i++;
		move(23 + i, SHIFT + 1);
	}
}

static void		vizual(int hor, int ver)
{
	t_bonus		viz;

	while (1)
	{
		if (!find_str_from_name(0, "    0123"))
			break ;
		output_score(hor, ver, &viz);
		print_map(ver, hor, &viz);
		refresh();
		system("sleep 0.1");
	}
	system("sleep 5");
	endwin();
}

int				main(void)
{
	t_bonus		viz;
	char		*sizes;
	int			hor;
	int			ver;

	hor = 0;
	ver = 0;
	viz.name_1 = find_str_from_name(0, "$$$ exec p1");
	viz.name_2 = find_str_from_name(0, "$$$ exec p2");
	sizes = find_str_from_name(0, "Plateau");
	ver = ft_atoi(&(sizes[8]));
	hor = ft_atoi(&(sizes[8 + size_num(ver)]));
	free(sizes);
	curs_start();
	create_header(hor, &viz);
	refresh();
	vizual(hor, ver);
	return (0);
}
