/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <bglinda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:19:58 by bglinda           #+#    #+#             */
/*   Updated: 2020/05/24 17:20:00 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			size_num(int num)
{
	int		size;

	size = 0;
	while (num > 0)
	{
		num /= 10;
		size++;
	}
	return (size);
}

char		*find_str_from_name(int fd, char *name)
{
	char	*ptr;

	ptr = NULL;
	while (get_next_line(fd, &ptr) == 1)
	{
		if (!ptr)
			return (NULL);
		if (ft_strncmp(ptr, name, 5) == 0)
			return (ptr);
		free(ptr);
		ptr = NULL;
	}
	return (NULL);
}

void		curs_start(void)
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	if (!initscr())
	{
		fprintf(stderr, "Error.\n");
		exit(1);
	}
	start_color();
	curs_set(0);
	init_pair(1, COLOR_WHITE, COLOR_GREEN);
	init_pair(2, COLOR_WHITE, COLOR_YELLOW);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
}

void		printw_color(char *str, int pair_num)
{
	attron(COLOR_PAIR(pair_num));
	printw("%s", str);
	attroff(COLOR_PAIR(pair_num));
}
