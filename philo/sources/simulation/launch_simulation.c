/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 21:06:51 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/12 16:00:34 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	launch_simulation(t_philosopher *philos, pthread_t **threads)
{
	size_t	index;

	*threads = malloc(philos->philosophers * sizeof **threads);
	if (! *threads)
		return (EXIT_FAILURE);
	while (index < philos->philosophers)
	{
		if (pthread_create(*threads + index, NULL, live, philos + index))
			return (EXIT_FAILURE);
		index ++;
	}
	return (EXIT_SUCCESS);
}
