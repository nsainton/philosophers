/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:37:28 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/13 10:38:17 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//static int	get_left_fork(pthread_mutex_t *mutex, t_cuint rank, t_cint *sim_state)
static int	get_left_fork(t_philosopher *philo)
{
	int	err;

	//printf("Trying to lock left fork number : %u\n", philo->rank - 1);
	err = pthread_mutex_lock(philo->forks + philo->rank - 1);
	if (err)
		return (STOP);
	if (continue_simulation(philo->sim_state, philo->sim_state_key) == STOP)
	{
		put_left_fork(philo->forks, philo->rank);
		return (STOP);
	}
	if (print_action(philo->sim_start, philo->rank, FRK))
		return (STOP);
	return (CONTINUE);
	/*
	err = pthread_mutex_lock(philo->left_fork);
	if (err)
		return (STOP);
	*/
}

//static int	get_right_fork(pthread_mutex_t *mutex, t_cuint philosophers, t_cuint rank, t_cint *sim_state)
static int	get_right_fork(t_philosopher *philo)
{
	int				err;

	if (philo->rank == philo->philosophers)
		err = pthread_mutex_lock(philo->forks);
	else
		err = pthread_mutex_lock(philo->forks + philo->rank);
	if (err)
		return (STOP);
	if (continue_simulation(philo->sim_state, philo->sim_state_key) == STOP)
	{
		put_right_fork(philo->forks, philo->philosophers, philo->rank);
		return (STOP);
	}
	if (print_action(philo->sim_start, philo->rank, FRK))
		return (STOP);
	return (CONTINUE);
}

/*
The first fork is fork number 1 and between 1 and 2
The last fork is fork number 0 and between N and 1
*/
//int	get_forks(pthread_mutex_t *mutex, t_cuint philosophers, t_cuint rank, t_cint *sim_state)
int	get_forks(t_philosopher *philo)
{
	int	err;

	if (continue_simulation(philo->sim_state, philo->sim_state_key) == STOP)
		return (STOP);
	if (philo->philosophers == 1)
		return (pthread_mutex_lock(philo->forks));
	if (philo->rank % 2)
	{
		err = get_right_fork(philo);
		if (err)
			return (err);
		return (get_left_fork(philo));
	}
	err = get_left_fork(philo);
	if (err)
		return (err);
	return (get_right_fork(philo));
}

