/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   survive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:07:32 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/10 13:52:28 by nsainton         ###   ########.fr       */
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
		philo->sim_state = DEAD;
		philo->state = DEAD;
		print_action(philo->sim_start, philo->rank, DIE);
		return (DEAD);
	}
	return (ALIVE);
}

static int	sleep_philosopher(t_philosopher *philo, t_cint status)
{
	if (check_status(status, philo->philosophers) == STOP)
		return (STOP);
	print_action(philo->sim_start, philo->rank, SLP);
	sleep(philo->sleep);
	return (CONTINUE);
}

static int	think_philosopher(t_philosopher *philo)
{
	if (is_alive(philo) == DEAD || continue_simulation(philo) == STOP)
		return (STOP);
	print_action(philo->sim_start, philo->rank, THK);
	return (EXIT_SUCCESS);
}
