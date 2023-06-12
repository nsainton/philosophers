/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:49:54 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/12 17:11:36 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_arg			args;
	t_philosopher	*philosophers;
	pthread_t		*threads;
	/*
	int	err;
	int	index;
	int	number;

	index = 0;
	while (index < ac)
	{
		number = ft_atoi_errors(*(av + index), "0123456789", &err);
		printf("The function atoi_errors %s return an error on argument : %s\n", err?"did":"didn't", *(av + index));
		printf("This is the number returned : %d\n", number);
		index ++;
	}
	*/
	if (ac < 5 || ac > 6)
	{
		printf("%s %s %s\n", USAGE, ARGS, OPT_ARG);
		return (EXIT_SUCCESS);
	}
	/*
	if (parse_args(&args, av + 1, (ac == 6)) || start_clock(&start))
		return (EXIT_FAILURE);
	sleep(1);
	print_action(start, 2, "has taken a fork");
	sleep(1);
	print_action(start, 1, "died");
	free(start);
	*/
	//printf("%s", av[0]);
	if (init(&args, &philosophers, (const char **)av + 1, ac == 6))
	{
		printf("Problem while initializing\n");
		return (EXIT_FAILURE);
	}
	if (launch_simulation(philosophers, &threads))
	{
		free_args(&args);
		free(philosophers);
		return (EXIT_FAILURE);
	}
	while (*args.sim_state == ALIVE)
	{
		usleep(1000);
		*args.sim_state = check_philo_status(philosophers);
	}
	kill_simulation(threads, philosophers->philosophers);
	free_args(&args);
	free(philosophers);
	free(threads);
	printf("DONE\n");
	return (EXIT_SUCCESS);
}
