/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:58:37 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/12 20:08:03 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philosopher(t_philosopher *philo, t_arg *args, const int rank)
{
	ft_bzero(philo, sizeof * philo);
	philo->philosophers = args->philosophers;
	philo->sleep = args->sleep;
	philo->eat = args->eat;
	philo->die = args->die;
	philo->rounds = args->rounds;
	philo->forks = args->forks;
	philo->sim_state = args->sim_state;
	philo->sim_start = args->sim_start;
	ft_memcpy(&philo->beg_last_meal, philo->sim_start\
	, sizeof philo->beg_last_meal);
	philo->rank = rank;
	philo->last_meal = args->meals + rank - 1;
}

int	init_philosophers(t_philosopher **philos, t_arg *args)
{
	t_uint	index;

	*philos = malloc(args->philosophers * sizeof **philos);
	if (! *philos)
		return (EXIT_FAILURE);
	index = 0;
	while (index < args->philosophers)
	{
		init_philosopher(*philos + index, args, index + 1);
		index ++;
	}
	return (EXIT_SUCCESS);
}
