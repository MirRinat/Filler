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

int	ft_len_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr && *arr)
	{
		while (arr[i])
			i++;
	}
	return (i);
}


void	ft_free_string_arr(char **t)
{
	char	**curr;

	if (t && *t)
	{
		curr = t;
		while (*curr)
			free(*(curr++));
		free(t);
		t = NULL;
	}
	if (t)
	{
		free(t);
		t = NULL;
	}
}

int valid_map(t_struct *map, char *buf, int gnl)
{
	char **tab;

	if (gnl == 0 || gnl == -1 || !buf || !buf[0])
	{
		ft_strdel(&buf);
		free_map((void **)map->map);
		return (-1);
	}
	tab = ft_strsplit(buf, ' ');
	if (ft_len_arr(tab) != 2 || ft_strlen(tab[0]) != 3
	|| ft_strlen(tab[1]) != map->hor_size)
	{
		ft_strdel(&buf);
		free_map((void **)map->map);
		ft_free_string_arr(tab);
		return (-1);
	}
	ft_strdel(&buf);
	ft_free_string_arr(tab);
	return (1);
}


static int	map_change(t_struct *map, int size)
{
	char	*buf;
	int		j;
	int		i;
	int		gnl;
//	char **tab;

	j = 0;
	while (j < size)
	{
		gnl = get_next_line(0, &buf);
//		if (valid_map(map, buf, gnl) == -1)
//			return (-1);
//		tab = ft_strsplit(buf, ' ');
		i = 0;
		while (i < map->hor_size)
		{
			if (ft_memchr("oO", buf[i + 4], 2))
				map->map[j][i] = (map->my_num == 1) ? -1 : 0;
			else if (ft_memchr("xX", buf[i + 4], 2))
				map->map[j][i] = (map->my_num == 1) ? 0 : -1;
			i++;
		}

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

//int valid_player(t_struct *map)
//{
//	char **arr1;
//	char *ptr;
//	int gnl;
//
//	gnl = get_next_line(0, &ptr);
//	if (gnl == 0 || gnl == -1 || !ptr || !ptr[0])
//	{
//		if (ptr)
//			ft_strdel(&ptr);
//		return (-1);
//	}
//	arr1 = ft_strsplit(ptr, ' ');
//	ft_strdel(&ptr);
//	if (ft_strcmp(arr1[0], "$$$") != 0 || ft_strcmp(arr1[1], "exec") != 0
//	|| ft_len_arr(arr1) != 5)
//	{
//		ft_free_string_arr(arr1);
//		return (-1);
//	}
//	if(ft_strlen(arr1[2]) == 2)
//	{
//		if (arr1[2][1] == '1' || arr1[2][1] == '2')
//			map->my_num = arr1[2][1] - '0';
//	}
//	ft_free_string_arr(arr1);
//	return (1);
//}
//
//int valid_shape(t_struct *map)
//{
//	int gnl;
//	char *ptr;
//	char **arr2;
//	char **arr3;
//
//	gnl = get_next_line(0, &ptr);
//	if (gnl == 0 || gnl == -1 || !ptr || !ptr[0])
//	{
//		ft_strdel(&ptr);
//		return (-1);
//	}
//	arr2 = ft_strsplit(ptr,' ');
//	ft_strdel(&ptr);
//	if 	(ft_len_arr(arr2) != 3 || ft_strcmp(arr2[0], "Plateau") != 0)
//	{
//		ft_free_string_arr(arr2);
//		return (-1);
//	}
//	map->ver_size = ft_atoi(arr2[1]);
//	arr3 = ft_strsplit(arr2[2], ':');
//	ft_free_string_arr(arr2);
//	map->hor_size = ft_atoi(arr3[0]);
//	ft_free_string_arr(arr3);
//	return (1);
//}

int			def_shape_map(t_struct *map)
{
//	if (valid_player(map) == -1)
//		return (-1);
//	if (valid_shape(map) == -1)
//		return (-1);
	char **arr2;
	char **arr3;
	char **arr1;
	char *ptr;
	int gnl;

	gnl = get_next_line(0, &ptr);
	if (gnl == 0 || gnl == -1 || !ptr || !ptr[0])
	{
		if (ptr)
			ft_strdel(&ptr);
		return (-1);
	}
	arr1 = ft_strsplit(ptr, ' ');
	ft_strdel(&ptr);
	if (ft_strcmp(arr1[0], "$$$") != 0 || ft_strcmp(arr1[1], "exec") != 0
		|| ft_len_arr(arr1) != 5)
	{
		ft_free_string_arr(arr1);
		return (-1);
	}
	if(ft_strlen(arr1[2]) == 2)
	{
		if (arr1[2][1] == '1' || arr1[2][1] == '2')
			map->my_num = arr1[2][1] - '0';
	}
	ft_free_string_arr(arr1);
	gnl = get_next_line(0, &ptr);
	if (gnl == 0 || gnl == -1 || !ptr || !ptr[0])
	{
		ft_strdel(&ptr);
		return (-1);
	}
	arr2 = ft_strsplit(ptr,' ');
	ft_strdel(&ptr);
	if 	(ft_len_arr(arr2) != 3 || ft_strcmp(arr2[0], "Plateau") != 0)
	{
		ft_free_string_arr(arr2);
		return (-1);
	}
	map->ver_size = ft_atoi(arr2[1]);
	arr3 = ft_strsplit(arr2[2], ':');
	ft_free_string_arr(arr2);
	map->hor_size = ft_atoi(arr3[0]);
	ft_free_string_arr(arr3);
	if (!(map->map = (int**)malloc(sizeof(int*) * (map->ver_size + 1))))
		return (-1);
	map->map[map->ver_size] = NULL;
	return (0);
}

int			create_map(t_struct *map)
{
	int		size;

	size = 0;
	if(def_shape_map(map) == -1)
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
	if (refresh_map(map, map->ver_size) == -1)
		return (-1);
	return (0);
}
