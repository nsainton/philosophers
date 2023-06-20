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

//Functions from file : survive.c
int				is_alive(t_philosopher *philo);

void			*live(void *philosopher);

//Functions from file : put_forks.c
int				put_left_fork(pthread_mutex_t *mutex, t_cuint rank);

int				put_right_fork(pthread_mutex_t *mutex, \
t_cuint philosophers, t_cuint rank);

int				put_forks(pthread_mutex_t *mutex, t_cuint philosophers, \
t_cuint rank);

//Functions from file : get_forks.c
int				get_forks(t_philosopher *philo);

//Functions from file : check.c
int				continue_simulation(const int *sim_state, \
pthread_mutex_t *sim_state_key);

int				check_philo_status(t_philosopher *philos);

//Functions from file : getvars.c
int				get_state(t_philosopher *philo);

int				get_sim_state(t_philosopher *philo);

//Functions from file : setvars.c
void			set_sim_state(int *state, const int new_state, \
pthread_mutex_t *key);

int				update_last_meal(struct timeval *last_meal, \
pthread_mutex_t *key);

//Functions from file : messages.c
void			parsing_error(const char *argument);

//Functions from file : timestamps.c
int				print_action(const struct timeval *start, t_cuint philo, \
t_cchar *action);

//Functions from file : launch_simulation.c
int				launch_simulation(t_philosopher *philos, \
pthread_t **threads);

int				kill_simulation(pthread_t *threads, \
const t_uint philosophers);

//Functions from file : allocate_ressources.c
int				start_clock(struct timeval **start);

int				init_locks(pthread_mutex_t **locks, \
const t_uint philosophers);

int				allocate_args(t_arg *args);

//Functions from file : parsing.c
int				parse_args(t_arg *arg, const char **av, const int opt);

//Functions from file : init_philosopher.c
void			init_philosopher(t_philosopher *philo, t_arg *args, \
const int rank);

int				init_philosophers(t_philosopher **philos, t_arg *args);

//Functions from file : init.c
int				init(t_arg *args, t_philosopher **philos, \
const char **av, const int opt);

//Functions from file : free_ressources.c
int				destroy_locks(pthread_mutex_t *locks, \
const t_uint philosophers);

int				free_args(t_arg *args);

//Functions from file : philo.c
//Functions from file : strings.c
char			*ft_strchr(const char *str, const int c);

size_t			ft_strlen(const char *str);

size_t			ft_strcat(char *dst, const char *src);

//Functions from file : numbers.c
unsigned int	count_digits(t_ull number);

void			fill_num(char **str, const t_ull number);

//Functions from file : memory.c
void			ft_bzero(void *s, size_t n);

void			ft_memset(void *s, t_cint c, size_t n);

void			ft_memcpy(void *dest, const void *src, const size_t n);

//Functions from file : atoi_errors.c
int				ft_atoi_errors(const char *number, const char *base, \
int *err);

//Functions from file : time_units.c
t_ull			timer_to_ms(const struct timeval *timer);

t_ull			timer_to_us(const struct timeval *timer);

t_ull			elapsed_time(pthread_mutex_t *lock, \
const struct timeval *timer, int *err);

//Functions from file : chrono.c
t_ull			chrono(int mode, unsigned int index, \
unsigned int philosophers);

//Functions from file : print.c
int				lprint(const char *s, ...);

#endif