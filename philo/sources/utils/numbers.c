/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:58:00 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/09 14:47:16 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	count_digits(t_ull number)
{
	t_uint	dig;

	if (! number)
		return (1);
	dig = 0;
	while (number)
	{
		number /= 10;
		dig ++;
	}
	return (dig);
}

void	fill_num(char **str, const t_ull number)
{
	if (number > 9)
	{
		fill_num(str, number / 10);
		fill_num(str, number % 10);
	}
	else
	{
		**str = number + '0';
		(*str)++;
	}
}
