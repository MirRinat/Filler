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

int			check_weight(t_struct *map, int weight, int i, int j)
{
	int		count;

	count = 0;
	if (j + 1 < map->hor_size && map->map[i][j + 1] == A)
	{
		map->map[i][j + 1] = weight;
		count++;
	}
	if (j - 1 >= 0 && map->map[i][j - 1] == A)
	{
		map->map[i][j - 1] = weight;
		count++;
	}
	if (i + 1 < map->ver_size && map->map[i + 1][j] == A)
	{
		map->map[i + 1][j] = weight;
		count++;
	}
	if (i - 1 >= 0 && map->map[i - 1][j] == A)
	{
		map->map[i - 1][j] = weight;
		count++;
	}
	return (count);
}

int			update_heatmap(t_struct *map, int find, int weight)
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
				if (map->map[i][j] == find)
					count += check_weight(map, weight, i, j);
				j++;
			}
			i++;
		}
		find++;
		weight++;
	}
	return (find);
}
