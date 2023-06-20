/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:49:12 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/11 20:57:55 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init(t_arg *args, t_philosopher **philos, const char **av, const int opt)
{
	if (parse_args(args, av, opt))
		return (EXIT_FAILURE);
	if (allocate_args(args))
		return (EXIT_FAILURE);
	if (init_philosophers(philos, args))
	{
		free_args(args);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
