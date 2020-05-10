/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_power.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:20:44 by bglinda           #+#    #+#             */
/*   Updated: 2020/03/13 17:21:03 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_to_power(unsigned long long a, int power)
{
	if (power == 0)
		return (1);
	a = a * ft_to_power(a, power - 1);
	return (a);
}
