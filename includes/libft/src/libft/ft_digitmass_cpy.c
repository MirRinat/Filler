/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitmass_cpy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:25:30 by bglinda           #+#    #+#             */
/*   Updated: 2020/03/13 17:25:40 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int			*ft_digitmass_cpy(int *stack, int size)
{
	int		*s_a;
	int		i;

	i = 0;
	s_a = (int*)malloc(sizeof(int) * size);
	if (!s_a)
		return (NULL);
	while (i < size)
	{
		s_a[i] = stack[i];
		i++;
	}
	return (s_a);
}
