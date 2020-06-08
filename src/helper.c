/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <bglinda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:19:30 by bglinda           #+#    #+#             */
/*   Updated: 2020/05/24 17:19:41 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		fillna(int *s, int n)
{
	int		i;

	i = 0;
	while (i < n)
		s[i++] = A;
}

int			skip_str(int line_count)
{
	char	*ptr;
	int		size;
	int		gnl;

	size = 0;
	ptr = NULL;
	while (size < line_count)
	{
		gnl = get_next_line(0, &ptr);
		if (gnl == 0 || gnl == -1)
			return (-1);
		free(ptr);
		size++;
	}
	return (1);
}

int			fresh(int return_val, t_struct *map)
{
	free_map((void **)map->map);
	free_map((void **)map->figure);
	return (return_val);
}

void		clear_map(t_struct *map)
{
	int		i;
	int		j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (j < map->hor_size)
		{
			map->map[i][j] = A;
			j++;
		}
		i++;
	}
	free_map((void **)map->figure);
}

void		*free_map(void **mas)
{
	char	**ptr;
	int		i;

	i = 0;
	if (!mas)
		return (NULL);
	ptr = (char**)mas;
	while (ptr[i] != NULL)
		free(ptr[i++]);
	free(ptr);
	return (NULL);
}
