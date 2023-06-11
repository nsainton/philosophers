/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:58:37 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/11 14:08:55 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philosopher(t_philosopher *philo, t_arg *args)
{
	ft_bzero(philo, sizeof * philo);
	philo->philosophers = args->philosophers;
	philo->sleep = args->sleep;
	philo->eat = args->eat;
	return (0);
}
