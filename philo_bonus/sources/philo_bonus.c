/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:32:11 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/13 16:41:02 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf("%s %s %s\n", USAGE, ARGS, OPT_ARG);
		return (EXIT_SUCCESS);
	}
	printf("%s\n", *av + 2);
	return (EXIT_SUCCESS);
}
