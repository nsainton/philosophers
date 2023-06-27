/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:21:29 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/20 12:32:44 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <limits.h>

unsigned int	ft_log(unsigned long long int number);

int	main(void)
{
	printf("Log of ULLONG_MAX : %u\n", ft_log(ULLONG_MAX));
	printf("Log of UINT_MAX : %u\n", ft_log(UINT_MAX));
	printf("Length of 'has taken a fork' : %ld\n", strlen("has taken a fork"));
	return (0);
}

unsigned int	ft_log(unsigned long long int number)
{
	unsigned int	ft_log;

	if (number == 0)
		return (1);
	ft_log = 0;
	while (number > 0)
	{
		number /= 10;
		ft_log ++;
	}
	return (ft_log);
}
