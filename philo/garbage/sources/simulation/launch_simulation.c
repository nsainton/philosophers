/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 21:06:51 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/12 16:44:24 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	launch_simulation(t_philosopher *philos, pthread_t **threads)
{
	t_uint	index;

	*threads = malloc(philos->philosophers * sizeof **threads);
	if (! *threads)
		return (EXIT_FAILURE);
	/*
	write(1, "Bonjour\n", ft_strlen("Bonjour\n"));
	printf("This is the number of philosophers : %u\n", philos->philosophers);
	*/
	index = 0;
	while (index < philos->philosophers)
	{
		if (pthread_create(*threads + index, NULL, live, philos + index))
			return (EXIT_FAILURE);
		//printf("Thread : %u created\n", philos->rank);
		index ++;
	}
	//printf("OK\n");
	return (EXIT_SUCCESS);
}

int	kill_simulation(pthread_t *threads, const t_uint philosophers)
{
	t_uint	index;
	int		err;

	index = 0;
	err = EXIT_SUCCESS;
	while (index < philosophers)
	{
		if (pthread_join(*(threads + index), NULL))
			err = EXIT_FAILURE;
		index ++;
	}
	return (err);
}
