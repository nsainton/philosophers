/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:49:54 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/08 16:33:47 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	int	err;
	int	index;
	int	number;

	index = 0;
	while (index < ac)
	{
		number = ft_atoi_errors(*(av + index), "0123456789", &err);
		printf("The function atoi_errors %s return an error on argument : %s\n", err?"did":"didn't", *(av + index));
		printf("This is the number returned : %d\n", number);
		index ++;
	}
	/*
	if (ac < 5 || ac > 6)
		printf("%s %s %s\n", USAGE, ARGS, OPT_ARG);
	printf("%s", av[0]);
	*/
	return (0);
}
