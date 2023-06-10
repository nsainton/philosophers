/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:05:01 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/10 14:25:46 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	continue_simulation(t_philosopher *philo)
{
	if (*philo->sim_state == DEAD)
		return (STOP);
	return (CONTINUE);
}

int	check_philo_status(t_philosopher *philos, t_cuint philosophers)
{
	t_uint	finished;
	t_uint	index;

	finished = 0;
	index = 0;
	while (index < philosophers)
	{
		if ((philos + index)->state == ALIVE && is_alive(philos + index) == DEAD)
			return (DEAD);
		if ((philos + index)->state == FINISHED)
			finished ++;
		index ++;
	}
	if (finished == philosophers)
		return (FINISHED);
	return (ALIVE);
}
