/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:06:52 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/09 14:21:35 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	get_num(unsigned int *num, const char *number, const char *base)
{
	size_t	len;
	char	*dig;

	*num = 0;
	len = ft_strlen(base);
	while (*number)
	{
		dig = ft_strchr(base, *number);
		if (! dig || *num > INT_MAX / len)
			return (EXIT_FAILURE);
		*num = *num * len + (dig - base);
		number ++;
	}
	return (EXIT_SUCCESS);
}

int	ft_atoi_errors(const char *number, const char *base, int *err)
{
	int				minus;
	unsigned int	num;

	minus = 1;
	if (*number == '-' || *number == '+')
	{
		minus = (*number == '+') * 2 - 1;
		number ++;
	}
	*err = get_num(&num, number, base);
	if (*err)
		return (EXIT_FAILURE);
	if ((num == (unsigned int)INT_MAX + 1 && minus == 1) \
	|| (num > (unsigned int)INT_MAX + 1))
		*err = 1;
	return (minus * num);
}
