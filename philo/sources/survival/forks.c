/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:37:28 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/09 17:47:03 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_left_fork(pthread_mutex_t *mutex, t_cuint rank)
{
	return (pthread_mutex_lock(mutex + rank - 1));
}

int	get_right_fork(pthread_mutex_t *mutex, t_cuint philosophers, t_cuint rank)
{
	if (rank == philosophers)
		return (pthread_mutex_lock(mutex));
	return (pthread_mutex_lock(mutex + rank));
}

/*
The first fork is fork number 1 and between 1 and 2
The last fork is fork number 0 and between N and 1
*/
int	get_fork(pthread_mutex_t *mutex, t_cuint philosophers, t_cuint rank)
{
	int	err;

	if (philosophers == 1)
		return (pthread_mutex_lock(mutex));
	if (rank % 2)
	{
		err = get_right_fork(mutex, philosophers, rank);
		if (err)
			return (err);
		return (get_left_fork(mutex, rank));
	}
	err = get_left_fork(mutex, rank);
	if (err)
		return (err);
	return (get_right_fork(mutex, philosophers, rank));
}
