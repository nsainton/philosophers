/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_int.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:14:46 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/09 14:24:48 by nsainton         ###   ########.fr       */
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

typedef const int				t_cint;

typedef unsigned int			t_uint;

typedef const unsigned int		t_cuint;

typedef const char				t_cchar;

typedef long long int			t_ll;

typedef unsigned long long int	t_ull;

typedef struct s_philosopher	t_philosopher;

typedef struct s_arg			t_arg;
#endif
