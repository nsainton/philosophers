/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:35:37 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/20 13:07:43 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//static char	*concat(t_ull timestamp, t_cuint philosopher, t_cchar *action)
static size_t	concat(t_ull timestamp, t_cuint philosopher, t_cchar *action, char message[MAX_LEN])
{
	/*
	t_uint	digs;
	char	*message;
	*/
	char	*cp;
	size_t	len;

	/*
	digs = count_digits(timestamp) + count_digits(philosopher);
	len = digs + 2 + ft_strlen(action) + 2;
	message = malloc(len);
	if (! message)
		return (NULL);
	*/
	ft_bzero(message, MAX_LEN);
	cp = message;
	fill_num(&cp, timestamp);
	*cp++ = ' ';
	fill_num(&cp, philosopher);
	*cp = ' ';
	len = ft_strcat(message, action);
	*(message + len) = '\n';
	*(message + len + 1) = 0;
	return (len + 1);
	//return (message);
}

int	print_action(const struct timeval *start, t_cuint philo, t_cchar *action)
{
	struct timeval	current;
	struct timeval	elapsed;
	char			message[MAX_LEN];
	t_ull			milliseconds;
	size_t			len;

	if (gettimeofday(&current, NULL) < 0)
		return (EXIT_FAILURE);
	timersub(&current, start, &elapsed);
	milliseconds = elapsed.tv_sec * 1000 + elapsed.tv_usec / 1000;
	len = concat(milliseconds, philo, action, message);
	/*
	if (! message)
		return (EXIT_FAILURE);
	*/
	write(1, message, len);
	//free(message);
	//printf("%llu %u %s\n", milliseconds, philo, action);
	return (EXIT_SUCCESS);
}
