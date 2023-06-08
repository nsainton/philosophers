/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_int.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:14:46 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/08 13:20:14 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_INT_H
# define PHILO_INT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# define USAGE "Usage: ./philo"
# define ARGS "number_of_philosophers time_to_die time_to_eat time_to_sleep"
# define OPT_ARG "[number_of_times_each_philosopher_must_eat]"
# define ERROR "Error encountered while parsing argument"

//Structures Definition
struct s_philosopher
{
	unsigned int	philosophers;
	unsigned int	sleep;
	unsigned int	eat;
	unsigned int	die;
	unsigned int	rounds;
	char			is_alive;
};

struct s_arg
{
	unsigned int	philosophers;
	unsigned int	sleep;
	unsigned int	eat;
	unsigned int	die;
	unsigned int	rounds;
};

//Typedefs
typedef struct s_philosopher	t_philosopher;

typedef struct s_arg			t_arg;

#endif
