/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:10:27 by bglinda           #+#    #+#             */
/*   Updated: 2019/04/18 17:10:27 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void		*ft_bzero(void *src, size_t n)
{
	char	*p;

	p = (char *)src;
	while (n > 0)
	{
		*p++ = '\0';
		n--;
	}
	return (src);
}
