/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <bglinda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:18:33 by bglinda           #+#    #+#             */
/*   Updated: 2020/05/24 17:18:41 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	map_change(t_struct *map, int size)
{
	char	*buf;
	int		j;
	int		i;

	j = 0;
	while (j < size)
	{
		if (get_next_line(0, &buf) == -1)
		{
			free_map((void **)map->map);
			return (-1);
		}
		i = 0;
		while (i < map->hor_size)
		{
			if (ft_memchr("oO", buf[i + 4], 2))
				map->map[j][i] = (map->my_num == 1) ? -1 : 0;
			else if (ft_memchr("xX", buf[i + 4], 2))
				map->map[j][i] = (map->my_num == 1) ? 0 : -1;
			i++;
		}
		free(buf);
		j++;
	}
	return (1);
}

int			refresh_map(t_struct *map, int size)
{
	char	*buf;

	if (map_change(map, size) == -1)
		return (-1);
	if (get_next_line(0, &buf) == -1)
	{
		free_map((void **)map->map);
		return (-1);
	}
	if (define_figure(buf, map) == -1)
		return (-1);
	return (1);
}

int			def_shape_map(t_struct *map)
{
	char	*ptr;

	if (get_next_line(0, &ptr) == -1)
		return (-1);
	map->my_num = ptr[10] - '0';
	free(ptr);
	if (get_next_line(0, &ptr) == -1)
		return (-1);
	map->ver_size = (int)ft_atoi(&(ptr[8]));
	map->hor_size = (int)ft_atoi(&(ptr[8 + size_num(map->ver_size) + 1]));
	if (!(map->map = (int**)malloc(sizeof(int*) * (map->ver_size + 1))))
		return (-1);
	map->map[map->ver_size] = NULL;
	free(ptr);
	return (0);
}

int			create_map(t_struct *map)
{
	int		size;

	size = 0;
	def_shape_map(map);
	while (size < map->ver_size)
	{
		if (!(map->map[size] = (int*)malloc(sizeof(int) * map->hor_size)))
		{
			free_map((void **)map->map);
			return (-1);
		}
		fillna(map->map[size++], map->hor_size);
	}
	if (!skip_str(1))
		return (-1);
	refresh_map(map, map->ver_size);
	return (0);
}
