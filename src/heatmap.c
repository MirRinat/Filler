/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <bglinda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:19:14 by bglinda           #+#    #+#             */
/*   Updated: 2020/05/24 17:19:19 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"



int			check_weight_diag(t_struct *map, int cost, int i, int j)
{
	int		count;

	count = 0;
	if (i - 1 >= 0 && j + 1 < map->hor_size && map->map[i - 1][j + 1] == A)
	{
		map->map[i - 1][j + 1] = cost;
		count++;
	}
	if (i - 1 >= 0 && j - 1 >= 0 && map->map[i - 1][j - 1] == A)
	{
		map->map[i - 1][j - 1] = cost;
		count++;
	}
	if (i + 1 < map->ver_size && j + 1 < map->hor_size
		&& map->map[i + 1][j + 1] == A)
	{
		map->map[i + 1][j + 1] = cost;
		count++;
	}
	if (i + 1 < map->ver_size && j - 1 >= 0 && map->map[i + 1][j - 1] == A)
	{
		map->map[i + 1][j - 1] = cost;
		count++;
	}
	return (count);
}

int			check_weight_hor_ver(t_struct *map, int cost, int i, int j)
{
	int		count;

	count = 0;
	if (j + 1 < map->hor_size && map->map[i][j + 1] == A)
	{
		map->map[i][j + 1] = cost;
		count++;
	}
	if (j - 1 >= 0 && map->map[i][j - 1] == A)
	{
		map->map[i][j - 1] = cost;
		count++;
	}
	if (i + 1 < map->ver_size && map->map[i + 1][j] == A)
	{
		map->map[i + 1][j] = cost;
		count++;
	}
	if (i - 1 >= 0 && map->map[i - 1][j] == A)
	{
		map->map[i - 1][j] = cost;
		count++;
	}
	return (count);
}

int			check_weight(t_struct *map, int cost, int i, int j)
{
	int		count;

	count = 0;
	count += check_weight_hor_ver(map, cost, i, j);
//	count += check_weight_diag(map, cost, i, j);

	return (count);
}

int			update_heatmap(t_struct *map, int find_to, int cost)
{
	int		count;
	int		i;
	int		j;

	count = 1;
	while (count > 0)
	{
		i = 0;
		count = 0;
		while (i < map->ver_size)
		{
			j = 0;
			while (j < map->hor_size)
			{
				if (map->map[i][j] == find_to)
					count += check_weight(map, cost, i, j);
				j++;
			}
			i++;
		}
		find_to++;
		cost++;
	}
	return (find_to);
}
