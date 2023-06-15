/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:57:58 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/12 20:21:57 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	parse_arg(unsigned int *arg, const char *str, const char *name)
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
int	parse_args(t_arg *arg, const char **av, const int opt)
{
	ft_bzero(arg, sizeof * arg);
	arg->rounds = 1;
	if (parse_arg(&arg->philosophers, *av, "number of philosophers"))
		return (EXIT_FAILURE);
	if (parse_arg(&arg->die, *(av + 1), "time to die"))
		return (EXIT_FAILURE);
	if (parse_arg(&arg->eat, *(av + 2), "time to eat"))
		return (EXIT_FAILURE);
	if (parse_arg(&arg->sleep, *(av + 3), "time to sleep"))
		return (EXIT_FAILURE);
	if (! opt)
	{
		arg->rounds = UINT_MAX;
		return (EXIT_SUCCESS);
	}
	if (parse_arg(&arg->rounds, *(av + 4), "number of rounds each philosopher \
must eat"))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
