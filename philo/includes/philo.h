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
//Functions from file : init.c
int		init_args(t_arg *arg, char **av, int ac);

//Functions from file : atoi_errors.c
int		ft_atoi_errors(const char *number, const char *base, int *err);

//Functions from file : strings.c
char	*ft_strchr(const char *str, const int c);

size_t	ft_strlen(const char *str);

#endif