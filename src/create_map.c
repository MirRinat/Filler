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

int			ft_len_arr(char **arr)
{
	int		i;

	i = 0;
	if (arr && *arr)
	{
		while (arr[i])
			i++;
	}
	return (i);
}

int			set_war(t_struct *map, int size)
{
	char	*str;
	int		j;
	int		i;
	int		gnl;

	j = 0;
	while (j < size)
	{
		gnl = get_next_line(0, &str);
		if (valid_map(map, str, gnl) == -1)
			return (-1);
		i = 0;
		while (i < map->hor_size)
		{
			if (ft_memchr("oO", str[i + 4], 2))
				map->map[j][i] = (map->my_num == 1) ? -1 : 0;
			else if (ft_memchr("xX", str[i + 4], 2))
				map->map[j][i] = (map->my_num == 2) ? -1 : 0;
			i++;
		}
		ft_strdel(&str);
		j++;
	}
	return (1);
}

int			update_map(t_struct *map, int size)
{
	if (set_war(map, size) == -1)
		return (-1);
	if (define_figure(map) == -1)
		return (-1);
	return (1);
}

int			def_shape_map(t_struct *map)
{
	if (valid_player(map) == -1)
		return (-1);
	if (valid_shape(map) == -1)
		return (-1);
	if (!(map->map = (int**)malloc(sizeof(int*) * (map->ver_size + 1))))
		return (-1);
	map->map[map->ver_size] = NULL;
	return (0);
}

int			create_map(t_struct *map)
{
	int		size;

	size = 0;
	if (def_shape_map(map) == -1)
		return (-1);
	while (size < map->ver_size)
	{
		if (!(map->map[size] = (int*)malloc(sizeof(int) * map->hor_size)))
		{
			free_map((void **)map->map);
			return (-1);
		}
		fillna(map->map[size++], map->hor_size);
	}
	if (skip_str(1) == -1)
		return (-1);
	if (update_map(map, map->ver_size) == -1)
		return (-1);
	return (0);
}
