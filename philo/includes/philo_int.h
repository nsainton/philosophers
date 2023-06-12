/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_int.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:14:46 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/12 20:16:34 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_INT_H
# define PHILO_INT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# define USAGE "Usage: ./philo"
# define ARGS "number_of_philosophers time_to_die time_to_eat time_to_sleep"
# define OPT_ARG "[number_of_times_each_philosopher_must_eat]"
# define ERR_STRING "Error encountered while parsing argument"
# define DEC "0123456789"
# define SLP "is sleeping"
# define FRK "has taken a fork"
# define EAT "is eating"
# define THK "is thinking"
# define DIE "died"

//Structures Definition
struct s_arg
{
	unsigned int	philosophers;
	unsigned int	sleep;
	unsigned int	eat;
	unsigned int	die;
	unsigned int	rounds;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*meals;
	pthread_mutex_t	*state_key;
	int				*sim_state;
	struct timeval	*sim_start;
};

struct s_philosopher
{
	unsigned int			philosophers;
	unsigned int			sleep;
	unsigned int			eat;
	unsigned int			die;
	unsigned int			rounds;
	unsigned int			rank;
	pthread_mutex_t			*forks;
	pthread_mutex_t			*last_meal;
	pthread_mutex_t			*state_key;
	int						state;
	int						*sim_state;
	struct timeval			beg_last_meal;
	const struct timeval	*sim_start;
};

//Enums Definitions
enum e_state
{
	DEAD = -1,
	ALIVE,
	FINISHED,
};

enum e_simulation
{
	CONTINUE,
	STOP
};
//Typedefs

typedef const int				t_cint;

typedef unsigned int			t_uint;

typedef const unsigned int		t_cuint;

typedef const char				t_cchar;

typedef long long int			t_ll;

typedef unsigned long long int	t_ull;

typedef struct s_philosopher	t_philosopher;

typedef struct s_arg			t_arg;
#endif
