/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:57:58 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/11 13:58:27 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_arg(unsigned int *arg, const char *str, const char *name)
{
	int	err;
	int	number;

	number = ft_atoi_errors(str, DEC, &err);
	if (number < 0 || err)
	{
		parsing_error(name);
		printf("This is the argument provided : %s\n", str);
		return (EXIT_FAILURE);
	}
	*arg = number;
	return (EXIT_SUCCESS);
}

/*
We set the number of rounds to one if no option is provided
So that it will always be true and our counter will not decrease in our
main loop for the philosophers.
*/
int	init_args(t_arg *arg, char **av, int opt)
{
	arg->rounds = 1;
	if (init_arg(&arg->philosophers, *av, "number of philosophers"))
		return (EXIT_FAILURE);
	if (init_arg(&arg->die, *(av + 1), "time to die"))
		return (EXIT_FAILURE);
	if (init_arg(&arg->eat, *(av + 2), "time to eat"))
		return (EXIT_FAILURE);
	if (init_arg(&arg->sleep, *(av + 3), "time to sleep"))
		return (EXIT_FAILURE);
	if (! opt)
	{
		arg->rounds = UINT_MAX;
		return (EXIT_SUCCESS);
	}
	if (init_arg(&arg->rounds, *(av + 4), "number of rounds each philosopher \
must eat"))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	start_clock(struct timeval **start)
{
	*start = malloc(sizeof **start);
	if (! *start || gettimeofday(*start, NULL) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
