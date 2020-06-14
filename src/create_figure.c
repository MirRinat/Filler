/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_figure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <bglinda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:18:07 by bglinda           #+#    #+#             */
/*   Updated: 2020/05/24 17:18:21 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		get_shape_map(t_struct *map, char **arr)
{
	char **width;

	map->ver_size = ft_atoi(arr[1]);
	width = ft_strsplit(arr[2], ':');
	free_map((void **)arr);
	map->hor_size = ft_atoi(width[0]);
	free_map((void **)width);
}

int			def_shape_fig(char *piece, t_struct *map)
{
	int		i;

	i = 0;
	if (valid_shape_fig(piece, map) == -1)
		return (-1);
	if (!(map->figure = (int**)malloc(sizeof(int*) * (map->f_ver + 1))))
	{
		free_map((void **)map->map);
		free_map((void **)map->figure);
		return (-1);
	}
	while (i < map->f_ver)
	{
		if (!(map->figure[i++] = (int*)malloc(sizeof(int) * map->f_width)))
		{
			free_map((void **)map->map);
			free_map((void **)map->figure);
			return (-1);
		}
	}
	map->figure[map->f_ver] = NULL;
	return (1);
}

int			create_fig(t_struct *map)
{
	char	*ptr;
	int		i;
	int		j;
	int		gnl;

	i = 0;
	while (i < map->f_ver)
	{
		gnl = get_next_line(0, &ptr);
		if (valid_figure(map, ptr, gnl) == -1)
			return (-1);
		j = 0;
		while (ptr[j] != '\0')
		{
			if (ptr[j] == '*')
				map->figure[i][j] = -1;
			else
				map->figure[i][j] = A;
			j++;
		}
		ft_strdel(&ptr);
		i++;
	}
	return (1);
}

int			define_figure(t_struct *map)
{
	char *buf;

	if (get_next_line(0, &buf) == -1)
	{
		free_map((void **)map->map);
		return (-1);
	}
	if (def_shape_fig(buf, map) == -1)
		return (-1);
	if (create_fig(map) == -1)
		return (-1);
	return (0);
}
