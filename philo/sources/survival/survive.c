/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   survive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:07:32 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/12 16:45:09 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_alive(t_philosopher *philo)
{
	int err;

	if (philo->state == DEAD || continue_simulation(philo->sim_state) == STOP)
		return (DEAD);
	if (elapsed_time(&philo->beg_last_meal, &err) >= philo->die || err)
	{
		*philo->sim_state = DEAD;
		philo->state = DEAD;
		print_action(philo->sim_start, philo->rank, DIE);
		return (DEAD);
	}
	return (ALIVE);
}

static int	sleep_philosopher(t_philosopher *philo)
{
	if (is_alive(philo) == DEAD \
	|| continue_simulation(philo->sim_state) == STOP)
		return (STOP);
	print_action(philo->sim_start, philo->rank, SLP);
	usleep(philo->sleep * 1000);
	return (CONTINUE);
}

static int	think_philosopher(t_philosopher *philo)
{
	if (is_alive(philo) == DEAD \
	|| continue_simulation(philo->sim_state) == STOP)
		return (STOP);
	print_action(philo->sim_start, philo->rank, THK);
	return (CONTINUE);
}

static int	eat_philosopher(t_philosopher *philo)
{
	if (continue_simulation(philo->sim_state) == STOP \
	|| gettimeofday(&philo->beg_last_meal, NULL) == -1)
		return (STOP);
	print_action(philo->sim_start, philo->rank, EAT);
	usleep(philo->eat * 1000);
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
	while (rounds > 0)
	{
		if (think_philosopher(philo) == STOP)
			return (philosopher);
		if (get_forks(philo) == STOP)
			return (philosopher);
		if (eat_philosopher(philo) == STOP)
			return (philosopher);
		if (put_forks(philo->forks, philo->philosophers, philo->rank))
			return (philosopher);
		if (sleep_philosopher(philo) == STOP)
			return (philosopher);
		rounds -= dec;
	}
	return (NULL);
}
