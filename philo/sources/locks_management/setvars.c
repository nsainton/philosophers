/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setvars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:42:36 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/13 11:03:19 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_sim_state(int *state, const int new_state, pthread_mutex_t *key)
{
	pthread_mutex_lock(key);
	*state = new_state;
	pthread_mutex_unlock(key);
}

int	update_last_meal(struct timeval *last_meal, pthread_mutex_t *key)
{
	int	err;

	pthread_mutex_lock(key);
	err = gettimeofday(last_meal, NULL);
	pthread_mutex_unlock(key);
	return (err);
}
