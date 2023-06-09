/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:08:14 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/31 16:08:14 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "philo_int.h"

//Functions from file : philo.c
//Functions from file : messages.c
void			parsing_error(const char *argument);

//Functions from file : timestamps.c
int				print_action(const struct timeval *start, t_cuint philo, \
t_cchar *action);

//Functions from file : survive.c
int				sleep_philosopher(t_philosopher *philo, \
t_cchar *status);

int				think_philosopher(t_philosopher *philo, char *status);

//Functions from file : check.c
int				check_status(t_cchar *status, t_cuint philosophers);

//Functions from file : forks.c
int				get_left_fork(pthread_mutex_t *mutex, t_cuint rank);

int				get_right_fork(pthread_mutex_t *mutex, \
t_cuint philosophers, t_cuint rank);

int				get_fork(pthread_mutex_t *mutex, t_cuint philosophers, \
t_cuint rank);

//Functions from file : init.c
int				init_args(t_arg *arg, char **av, int opt);

int				start_clock(struct timeval **start);

//Functions from file : time_units.c
t_ull			timer_to_ms(const struct timeval *timer);

t_ull			elapsed_time(const struct timeval *timer, int *err);

//Functions from file : atoi_errors.c
int				ft_atoi_errors(const char *number, const char *base, \
int *err);

//Functions from file : strings.c
char			*ft_strchr(const char *str, const int c);

size_t			ft_strlen(const char *str);

char			*ft_strcat(char *dst, const char *src);

//Functions from file : memory.c
void			ft_bzero(void *s, size_t n);

void			ft_memset(void *s, t_cint c, size_t n);

//Functions from file : numbers.c
unsigned int	count_digits(t_ull number);

void			fill_num(char **str, const t_ull number);

#endif