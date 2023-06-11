/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_ressources.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:38:40 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/11 20:40:50 by nsainton         ###   ########.fr       */
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

int	destroy_forks(pthread_mutex_t *forks, const t_uint philosophers)
{
	int		err;
	t_uint	index;

	err = EXIT_SUCCESS;
	index = 0;
	while (index < philosophers)
	{
		if (pthread_mutex_destroy(forks + index))
			err = EXIT_FAILURE;
		index ++;
	}
	return (err);
}

int	init_forks(pthread_mutex_t **forks, const t_uint philosophers)
{
	t_uint	index;

	*forks = malloc(philosophers * sizeof **forks);
	if (! *forks)
		return (EXIT_FAILURE);
	index = 0;
	while (index < philosophers)
	{
		if (pthread_mutex_init(*forks + index, NULL))
		{
			destroy_forks(*forks, index);
			free(*forks);
			return (EXIT_FAILURE);
		}
		index ++;
	}
	return (EXIT_SUCCESS);
}

int	allocate_arg(t_arg *args)
{
	args->sim_state = malloc(sizeof *args->sim_state);
	if (! args->sim_state)
		return (EXIT_FAILURE);
	args->sim_state = CONTINUE;
	if (start_clock(&args->sim_start))
	{
		free(args->sim_state);
		return (EXIT_FAILURE);
	}
	if (init_forks(&args->forks, args->philosophers))
	{
		free(args->sim_state);
		free(args->sim_start);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	free_args(t_arg *args)
{
	free(args->sim_state);
	free(args->sim_start);
	return (destroy_forks(args->forks, args->philosophers));
}
