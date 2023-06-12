/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ressources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:48:02 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/12 20:07:22 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_locks(pthread_mutex_t *locks, const t_uint philosophers)
{
	int		err;
	t_uint	index;

	err = EXIT_SUCCESS;
	index = 0;
	while (index < philosophers)
	{
		if (pthread_mutex_destroy(locks + index))
			err = EXIT_FAILURE;
		index ++;
	}
	return (err);
}

int	free_args(t_arg *args)
{
	int	err;

	free(args->sim_state);
	free(args->sim_start);
	err = destroy_locks(args->forks, args->philosophers);
	free(args->forks);
	err = (destroy_locks(args->meals, args->philosophers) || err) * err;
	free(args->meals);
	return (err);
}
