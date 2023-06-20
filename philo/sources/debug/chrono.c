/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chrono.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:28:00 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/20 15:56:43 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ull	chrono(int mode, unsigned int index, unsigned int philosophers)
{
	static struct timeval	*beginning;
	struct timeval			current;
	struct timeval			end;

	if (! beginning)
	{
		beginning = malloc(philosophers * sizeof current);
		if (! beginning)
			return (ULLONG_MAX);
	}
	if (! mode)
	{
		gettimeofday(beginning + index, NULL);
		return (0);
	}
	if (mode < 0)
	{
		free(beginning);
		beginning = NULL;
		return (0);
	}
	if (gettimeofday(&current, NULL))
		return (ULLONG_MAX);
	timersub(&current, beginning + index, &end);
	return (timer_to_us(&end));
}
