/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <bglinda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 17:20:11 by bglinda           #+#    #+#             */
/*   Updated: 2020/05/24 17:20:12 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

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

int			main(void)
{
	t_struct map;

	if (create_map(&map) == -1)
		return (-1);
	print_heatmap(&map);
	printf("\n");
	if (solver(&map) == -1)
		return (-1);
	free_map((void **)map.map);
	free_map((void **)map.figure);

	return (0);
}
