/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   survive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:07:32 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/11 13:45:54 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_alive(t_philosopher *philo)
{
	int err;

	if (philo->state == DEAD)
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
	usleep(philo->sleep * 1000);
	return (CONTINUE);
}

int	live(t_philosopher *philo)
{
	t_uint	dec;
	t_uint	rounds;

	rounds = philo->rounds;
	dec = (rounds != UINT_MAX);
	while (rounds > 0)
	{
		if (think_philosopher(philo) == STOP)
			return (STOP);
		if (get_forks(philo) == STOP)
			return (STOP);
		if (eat_philosopher(philo) == STOP)
			return (STOP);
		if (sleep_philosopher(philo) == STOP)
			return (STOP);
		rounds -= dec;
	}
	return (FINISHED);
}
