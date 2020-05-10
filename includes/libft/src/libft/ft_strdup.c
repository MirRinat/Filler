/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:19:43 by bglinda           #+#    #+#             */
/*   Updated: 2019/04/24 14:41:26 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char		*ft_strdup(const char *src)
{
	int		len;
	char	*s;

	len = ft_strlen(src);
	if (!(s = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_strcpy(s, src);
	return (s);
}
