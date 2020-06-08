/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <bglinda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 20:56:36 by bglinda           #+#    #+#             */
/*   Updated: 2020/06/07 20:56:40 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			valid_map(t_struct *map, char *buf, int gnl)
{
	char	**tab;

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
		free_map((void **)tab);
		return (-1);
	}
	free_map((void **)tab);
	return (1);
}

int			valid_player(t_struct *map)
{
	char	**arr1;
	char	*ptr;
	int		gnl;

	gnl = get_next_line(0, &ptr);
	if (gnl == 0 || gnl == -1 || !ptr || !ptr[0])
	{
		ft_strdel(&ptr);
		return (-1);
	}
	arr1 = ft_strsplit(ptr, ' ');
	ft_strdel(&ptr);
	if (ft_strcmp(arr1[0], "$$$") != 0 || ft_strcmp(arr1[1], "exec") != 0
		|| ft_len_arr(arr1) != 5)
	{
		free_map((void **)arr1);
		return (-1);
	}
	if (ft_strlen(arr1[2]) == 2)
	{
		if (arr1[2][1] == '1' || arr1[2][1] == '2')
			map->my_num = arr1[2][1] - '0';
	}
	free_map((void **)arr1);
	return (1);
}

int			valid_shape(t_struct *map)
{
	int		gnl;
	char	*ptr;
	char	**arr2;
	char	**arr3;

	gnl = get_next_line(0, &ptr);
	if (gnl == 0 || gnl == -1 || !ptr || !ptr[0])
	{
		ft_strdel(&ptr);
		return (-1);
	}
	arr2 = ft_strsplit(ptr, ' ');
	ft_strdel(&ptr);
	if (ft_len_arr(arr2) != 3 || ft_strcmp(arr2[0], "Plateau") != 0)
	{
		free_map((void **)arr2);
		return (-1);
	}
	map->ver_size = ft_atoi(arr2[1]);
	arr3 = ft_strsplit(arr2[2], ':');
	free_map((void **)arr2);
	map->hor_size = ft_atoi(arr3[0]);
	free_map((void **)arr3);
	return (1);
}

int			valid_shape_fig(char *piece, t_struct *map)
{
	char	**arr;
	char	**tab;

	tab = ft_strsplit(piece, ' ');
	ft_strdel(&piece);
	if (ft_strcmp(tab[0], "Piece") != 0 || ft_len_arr(tab) != 3)
	{
		free_map((void **)map->map);
		free_map((void **)tab);
		return (-1);
	}
	map->f_ver = ft_atoi(tab[1]);
	arr = ft_strsplit(tab[2], ':');
	map->f_width = ft_atoi(arr[0]);
	free_map((void **)tab);
	free_map((void **)arr);
	return (1);
}

int			valid_figure(t_struct *map, char *ptr, int gnl)
{
	if (gnl == 0 || gnl == -1 || !ptr || !ptr[0]
		|| ft_strlen(ptr) != map->f_width)
	{
		if (ptr)
			ft_strdel(&ptr);
		free_map((void **)map->figure);
		free_map((void **)map->map);
		return (-1);
	}
	return (1);
}
