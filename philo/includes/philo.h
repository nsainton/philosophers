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

//Functions from file : timestamps.c
int				print_action(const struct timeval *start, t_cuint philo, \
t_cchar *action);

//Functions from file : messages.c
void			parsing_error(const char *argument);

//Functions from file : philo.c
//Functions from file : init_philosopher.c
int				init_philosopher(t_philosopher *philo, t_arg *args, \
const int rank);

//Functions from file : init.c
int				init_args(t_arg *arg, char **av, int opt);

//Functions from file : allocate_ressources.c
int				start_clock(struct timeval **start);

int				destroy_forks(pthread_mutex_t *forks, \
const t_uint philosophers);

int				init_forks(pthread_mutex_t **forks, \
const t_uint philosophers);

int				allocate_arg(t_arg *args);

int				free_args(t_arg *args);

//Functions from file : memory.c
void			ft_bzero(void *s, size_t n);

void			ft_memset(void *s, t_cint c, size_t n);

void			ft_memcpy(void *dest, const void *src, const size_t n);

//Functions from file : time_units.c
t_ull			timer_to_ms(const struct timeval *timer);

t_ull			elapsed_time(const struct timeval *timer, int *err);

//Functions from file : strings.c
char			*ft_strchr(const char *str, const int c);

size_t			ft_strlen(const char *str);

char			*ft_strcat(char *dst, const char *src);

//Functions from file : numbers.c
unsigned int	count_digits(t_ull number);

void			fill_num(char **str, const t_ull number);

//Functions from file : atoi_errors.c
int				ft_atoi_errors(const char *number, const char *base, \
int *err);

//Functions from file : check.c
int				continue_simulation(const int *sim_state);

int				check_philo_status(t_philosopher *philos, \
t_cuint philosophers);

//Functions from file : get_forks.c
int				get_forks(t_philosopher *philo);

//Functions from file : survive.c
int				is_alive(t_philosopher *philo);

int				live(t_philosopher *philo);

//Functions from file : put_forks.c
int				put_left_fork(pthread_mutex_t *mutex, t_cuint rank);

int				put_right_fork(pthread_mutex_t *mutex, \
t_cuint philosophers, t_cuint rank);

int				put_forks(pthread_mutex_t *mutex, t_cuint philosophers, \
t_cuint rank);

#endif