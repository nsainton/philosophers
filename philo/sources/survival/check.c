/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:05:01 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/12 16:06:05 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	continue_simulation(const int *sim_state)
{
	if (*sim_state == DEAD)
		return (STOP);
	return (CONTINUE);
}

int	check_philo_status(t_philosopher *philos)
{
	t_uint	finished;
	t_uint	index;

	finished = 0;
	index = 0;
	while (index < philos->philosophers)
	{
		if ((philos + index)->state == ALIVE && is_alive(philos + index) == DEAD)
			return (DEAD);
		if ((philos + index)->state == FINISHED)
			finished ++;
		index ++;
	}
	if (finished == philos->philosophers)
		return (FINISHED);
	return (ALIVE);
}
