/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_ressources.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:38:40 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/12 20:12:20 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_clock(struct timeval **start)
{
	*start = malloc(sizeof **start);
	if (! *start)
		return (EXIT_FAILURE);
	if (gettimeofday(*start, NULL) < 0)
	{
		free(*start);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_locks(pthread_mutex_t **locks, const t_uint philosophers)
{
	t_uint	index;

	*locks = malloc(philosophers * sizeof **locks);
	if (! *locks)
		return (EXIT_FAILURE);
	index = 0;
	while (index < philosophers)
	{
		if (pthread_mutex_init(*locks + index, NULL))
		{
			destroy_locks(*locks, index);
			free(*locks);
			return (EXIT_FAILURE);
		}
		index ++;
	}
	return (EXIT_SUCCESS);
}

int	allocate_args(t_arg *args)
{
	args->sim_state = malloc(sizeof *args->sim_state);
	if (! args->sim_state)
		return (EXIT_FAILURE);
	*args->sim_state = CONTINUE;
	if (start_clock(&args->sim_start))
	{
		free(args->sim_state);
		return (EXIT_FAILURE);
	}
	if (init_locks(&args->forks, args->philosophers))
	{
		free(args->sim_state);
		free(args->sim_start);
		return (EXIT_FAILURE);
	}
	if (init_locks(&args->meals, args->philosophers))
	{
		free(args->sim_state);
		free(args->sim_start);
		destroy_locks(args->forks, args->philosophers);
		free(args->forks);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
