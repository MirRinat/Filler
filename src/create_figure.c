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

void		cut_by_hor(t_struct *map)
{
	int		i;
	int		j;

	j = map->f_width - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < map->f_ver && map->figure[i][j] == A)
			i++;
		if (i != map->f_ver)
			return ;
		(map->right_shift)++;
		j--;
	}
}

void		cut_by_ver(t_struct *map)
{
	int		i;
	int		j;

	i = map->f_ver - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < map->f_width && map->figure[i][j] == A)
			j++;
		if (j != map->f_width)
			break ;
		(map->ver_shift)++;
		i--;
	}
}

int	valid_shape_fig(char **tab, t_struct *map)
{
	char	**arr;

	if (ft_strcmp(tab[0], "Piece") != 0 || ft_len_arr(tab) != 3)
	{
		free_map((void **)map->map);
		ft_free_string_arr(tab);
		return (-1);
	}
	map->f_ver = ft_atoi(tab[1]);
	arr = ft_strsplit(tab[2], ':');
	map->f_width = ft_atoi(arr[0]);
	ft_free_string_arr(tab);
	ft_free_string_arr(arr);
	return (1);
}

int			def_shape_fig(char *piece, t_struct *map)
{
	int		i;
	char **tab;


	i = 0;
	tab = ft_strsplit(piece, ' ');
	ft_strdel(&piece);
	if (valid_shape_fig(tab, map) == -1)
		return (-1);
	map->ver_shift = 0;
	if (!(map->figure = (int**)malloc(sizeof(int*) * (map->f_ver + 1))))
		return (-1);
	while (i < map->f_ver)
	{
		if (!(map->figure[i++] = (int*)malloc(sizeof(int) * map->f_width)))
		{
			free_map((void **)map->figure);
			return (-1);
		}
	}
	map->figure[map->f_ver] = NULL;
	return (1);
}
int valid_figure(t_struct *map, char *ptr, int gnl)
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
//		if (valid_figure(map, ptr, gnl) == -1)
//			return (-1);
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

int			define_figure(char *piece, t_struct *map)
{
	if (def_shape_fig(piece, map) == -1)
		return (-1);
	if (create_fig(map) == -1)
		return (-1);
	map->ver_shift = 0;
	map->right_shift = 0;
	cut_by_ver(map);
	cut_by_hor(map);
	return (0);
}
