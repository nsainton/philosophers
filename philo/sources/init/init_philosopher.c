/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:58:37 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/11 14:19:21 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philosopher(t_philosopher *philo, t_arg *args, const int rank)
{
	ft_bzero(philo, sizeof * philo);
	philo->philosophers = args->philosophers;
	philo->sleep = args->sleep;
	philo->eat = args->eat;
	philo->die = args->die;
	philo->rounds = args->rounds;
	philo->forks = args->forks;
	philo->sim_state = args->sim_state;
	philo->sim_start = args->sim_start;
	ft_memcpy(&philo->beg_last_meal, philo->sim_start\
	, sizeof philo->beg_last_meal);
	philo->rank = rank;
	return (0);
}
