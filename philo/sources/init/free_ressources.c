/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ressources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:48:02 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/11 21:04:08 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	free_args(t_arg *args)
{
	int	err;

	free(args->sim_state);
	free(args->sim_start);
	err = destroy_forks(args->forks, args->philosophers);
	free(args->forks);
	return (err);
}
