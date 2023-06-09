/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   survive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:07:32 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/09 17:48:45 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_alive(t_philosopher *philo)
{
	int err;

	if (elapsed_time(&philo->beg_last_meal, &err) >= philo->die || err)
	{
		print_action(philo->sim_start, philo->rank, DIE);
		return (DEAD);
	}
	return (ALIVE);
}

int	sleep_philosopher(t_philosopher *philo, t_cchar *status)
{
	if (check_status(status, philo->philosophers) == STOP)
		return (STOP);
	print_action(philo->sim_start, philo->rank, SLP);
	sleep(philo->sleep);
	return (CONTINUE);
}

int	think_philosopher(t_philosopher *philo, char *status)
{
	if (is_alive(philo) == DEAD)
	{
		*(status + philo->rank - 1) = DEAD;
		return (STOP);
	}
	if (check_status(status, philo->philosophers) == STOP)
		return (STOP);
	print_action(philo->sim_start, philo->rank, THK);
	return (EXIT_SUCCESS);
}
