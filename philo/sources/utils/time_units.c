/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_units.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:03:36 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/12 20:00:56 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ull	timer_to_ms(const struct timeval *timer)
{
	return (timer->tv_sec * 1000 + timer->tv_usec / 1000);
}

t_ull	elapsed_time(pthread_mutex_t *lock, const struct timeval *timer, int *err)
{
	struct timeval	current;
	struct timeval	elapsed;

	if (gettimeofday(&current, NULL) < 0)
	{
		*err = EXIT_FAILURE;
		return (0);
	}
	*err = EXIT_SUCCESS;
	pthread_mutex_lock(lock);
	timersub(&current, timer, &elapsed);
	pthread_mutex_unlock(lock);
	return (timer_to_ms(&elapsed));
}
