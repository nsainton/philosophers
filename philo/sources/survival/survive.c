/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   survive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:07:32 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/20 15:51:32 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_alive(t_philosopher *philo)
{
	int err;
	int	state;

	state = get_state(philo);
	if (state == FINISHED)
		return (FINISHED);
	if (state == DEAD \
	|| continue_simulation(philo->sim_state, philo->sim_state_key) == STOP)
		return (DEAD);
	if (elapsed_time(philo->last_meal, &philo->beg_last_meal, &err) \
	>= philo->die || err)
	{
		set_sim_state(philo->sim_state, DEAD, philo->sim_state_key);
		pthread_mutex_lock(philo->state_key);
		philo->state = DEAD;
		pthread_mutex_unlock(philo->state_key);
		//printf("I report my death\n");
		print_action(philo->sim_start, philo->rank, DIE);
		return (DEAD);
	}
	return (ALIVE);
}

static int	sleep_philosopher(t_philosopher *philo)
{
	chrono(0, philo->rank - 1, philo->philosophers);
	if (is_alive(philo) == DEAD \
	|| continue_simulation(philo->sim_state, philo->sim_state_key) \
	== STOP)
		return (STOP);
	lprint("The check for sleep took : %lld microseconds\n", chrono(1, philo->rank - 1, philo->philosophers));
	print_action(philo->sim_start, philo->rank, SLP);
	usleep(philo->sleep * 1000);
	lprint("sleep took : %lld microseconds\n", chrono(1, philo->rank - 1, philo->philosophers));
	return (CONTINUE);
}

static int	think_philosopher(t_philosopher *philo)
{
	chrono(0, philo->rank - 1, philo->philosophers);
	if (is_alive(philo) == DEAD \
	|| continue_simulation(philo->sim_state, philo->sim_state_key) \
	== STOP)
		return (STOP);
	lprint("The check for think took : %lld microseconds\n", chrono(1, philo->rank - 1, philo->philosophers));
	print_action(philo->sim_start, philo->rank, THK);
	return (CONTINUE);
}

static int	eat_philosopher(t_philosopher *philo)
{
	chrono(0, philo->rank - 1, philo->philosophers);
	if (continue_simulation(philo->sim_state, philo->sim_state_key) \
	== STOP)
		return (STOP);
	if (update_last_meal(&philo->beg_last_meal, philo->last_meal) \
	== -1)
		return (STOP);
	lprint("The check for eat took : %lld microseconds\n", chrono(1, philo->rank - 1, philo->philosophers));
	print_action(philo->sim_start, philo->rank, EAT);
	usleep(philo->eat * 1000);
	lprint("eat took : %lld microseconds\n", chrono(1, philo->rank - 1, philo->philosophers));
	return (CONTINUE);
}

void	*live(void *philosopher)
{
	t_uint			dec;
	t_uint			rounds;
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	rounds = philo->rounds;
	dec = (rounds != UINT_MAX);
	if (philo->rank % 2)
		usleep(philo->sleep * 500);
	while (rounds > 0)
	{
		if (think_philosopher(philo) == STOP)
			return (philosopher);
		if (get_forks(philo) == STOP)
			return (philosopher);
		if (eat_philosopher(philo) == STOP)
		{
			put_forks(philo->forks, philo->philosophers, philo->rank);
			return (philosopher);
		}
		put_forks(philo->forks, philo->philosophers, philo->rank);
		if (sleep_philosopher(philo) == STOP)
			return (philosopher);
		rounds -= dec;
	}
	philo->state = FINISHED;
	return (NULL);
}
