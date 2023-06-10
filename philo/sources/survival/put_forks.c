/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:03:56 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/10 14:26:24 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	put_left_fork(pthread_mutex_t *mutex, t_cuint rank)
{
	return (pthread_mutex_unlock(mutex + rank - 1));
}

static int	put_right_fork(pthread_mutex_t *mutex, t_cuint philosophers, t_cuint rank)
{
	if (rank == philosophers)
		return (pthread_mutex_unlock(mutex));
	return (pthread_mutex_unlock(mutex + rank));
}

int	put_forks(pthread_mutex_t *mutex, t_cuint philosophers, t_cuint rank)
{
	int	err;

	if (philosophers == 1)
		return (pthread_mutex_unlock(mutex));
	if (rank % 2)
	{
		err = put_left_fork(mutex, rank);
		if (err)
			return (err);
		return (put_right_fork(mutex, philosophers, rank));
	}
	err = put_right_fork(mutex, philosophers, rank);
	if (err)
		return (err);
	return (put_left_fork(mutex, rank));
}
