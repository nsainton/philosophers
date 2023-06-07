/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:06:52 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/07 18:10:32 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi_errors(const char *number, const char *base, int *err)
{
	int				number;
	int				minus;
	unsigned int	num;

	minus = 1;
	if (*number == '-')
	{
		minus = -1;
		number ++;
	}
	*err = fill_num(&num, number, base);
