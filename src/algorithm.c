/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <bglinda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:17:11 by bglinda           #+#    #+#             */
/*   Updated: 2020/05/24 17:17:19 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			check_inter(int map_value, int figure_value, int *inter,
		int *count)
{
	if (map_value == -1 && figure_value == -1)
		(*inter)++;
	if (map_value == 0 && figure_value == -1)
		return (-1);
	if (*inter > 1)
		return (-1);
	if (map_value > 0 && figure_value == -1)
		(*count) += map_value;
	return (1);
}

int			set_figure(t_struct *map, int i, int j, int *inter)
{
	int		count;
	int		ptr_j;
	int		x;
	int		y;

	y = 0;
	count = 0;
	*inter = 0;
	ptr_j = j;
	while (i < map->ver_size && y < map->f_ver)
	{
		x = 0;
		j = ptr_j;
		while (x < map->f_width && j < map->hor_size)
		{
			if (check_inter(map->map[i][j], map->figure[y][x],
					inter, &count) == -1)
				return (-1);
			j++;
			x++;
		}
		i++;
		y++;
	}
	return (count);
}

int			change_values(t_struct *map, int i, int j, int count)
{
	map->my_x = j;
	map->my_y = i;
	return (count);
}

void		find_place(t_struct *map)
{
	int		i;
	int		j;
	int		count;
	int		current;
	int		intersection;

	current = MAX;
	i = 0;
	while (i < map->ver_size)
	{
		j = 0;
		while (j < map->hor_size)
		{
			if (((i + map->f_ver - map->ver_shift - 1) < map->ver_size)
				&& (j + map->f_width - map->right_shift - 1 < map->hor_size))
			{
				count = set_figure(map, i, j, &intersection);
				if (count > 0 && intersection > 0 && count < current)
					current = change_values(map, i, j, count);
			}
			j++;
		}
		i++;
	}
}

int			solver(t_struct *map)
{
	char	*x;
	char	*y;

	while (1)
	{
		update_heatmap(map, 0, 1);
		find_place(map);
		x = ft_itoa(map->my_x);
		y = ft_itoa(map->my_y);
		if (!(x && y))
			return (fresh(-1, map));
		ft_printf("%s %s\n", y, x);
		free(x);
		free(y);
		if (map->my_x < 0 || map->my_y < 0)
			break ;
		if (!skip_str(2))
			return (fresh(-1, map));
		clear_map(map);
		if (refresh_map(map, map->ver_size) == -1)
			return (-1);
		map->my_x = -1;
	}
	return (0);
}
