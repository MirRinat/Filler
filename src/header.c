/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <bglinda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:18:58 by bglinda           #+#    #+#             */
/*   Updated: 2020/05/24 17:19:05 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			print_score(int score, int square, int position, char *icon)
{
	float		procent;
	int			proc_ptr;
	int			i;

	i = 0;
	move(16, position);
	procent = ((float)score / (float)square) * 100.0;
	proc_ptr = (int)procent;
	while (i < 20)
	{
		if (proc_ptr / 5 > 0)
		{
			printw("✔");
			proc_ptr = proc_ptr - 5;
		}
		else
			printw(".");
		i++;
	}
	move(18, position);
	printw("%s ", icon);
	printw("%d", (int)procent);
	printw("%% ");
}

void			output_score(int hor, int ver, t_bonus *viz)
{
	int			size;

	if (hor < 35)
		size = -7;
	else
		size = 15;
	print_score(viz->o_score, (hor * ver), SHIFT + size, "💊");
	attron(COLOR_PAIR(6));
	printw("%d", viz->o_score);
	attroff(COLOR_PAIR(6));
	print_score(viz->x_score, (hor * ver), SHIFT + size + 30, "👑");
	attron(COLOR_PAIR(6));
	printw("%d", viz->x_score);
	attroff(COLOR_PAIR(6));
}

void			output_player_name(char *player_name)
{
	int			i;
	int			len;

	i = 0;
	i = ft_strlen(player_name);
	while (player_name[i] != '/' && i > 0)
		i--;
	len = ft_strlen(player_name) - i - 2;
	i++;
	printw("%.*s", len, &(player_name[i]));
}

void			create_header(int hor, t_bonus *viz)
{
	int			size;

	if (hor < 35)
		size = -15;
	else
		size = 5;
	printw("\n\n");
	move(14, SHIFT + size + 15);
	output_player_name(viz->name_1);
	printw("%*s", 16, "");
	output_player_name(viz->name_2);
	free(viz->name_1);
	free(viz->name_2);
	move(20, 0);
}
