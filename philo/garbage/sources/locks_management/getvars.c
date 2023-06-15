/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getvars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:55:37 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/13 11:03:07 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_state(t_philosopher *philo)
{
	int	state;

	pthread_mutex_lock(philo->state_key);
	state = philo->state;
	pthread_mutex_unlock(philo->state_key);
	return (state);
}

int	get_sim_state(t_philosopher *philo)
{
	int	state;

	pthread_mutex_lock(philo->sim_state_key);
	state = *philo->sim_state;
	pthread_mutex_unlock(philo->sim_state_key);
	return (state);
}
