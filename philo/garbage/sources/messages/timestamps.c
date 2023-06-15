/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:35:37 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/13 13:15:47 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
4 additionnals blocs in malloc for the 2 spaces after the numbers
The '\n' and the '\0'
*/
/*
static char	*concat(t_ull timestamp, t_cuint philosopher, t_cchar *action)
{
	t_uint	digs;
	char	*msg;
	char	*cp;
	size_t	len;

	digs = count_digits(timestamp) + count_digits(philosopher);
	len = digs + 2 + ft_strlen(action) + 2;
	msg = malloc(len);
	if (! msg)
		return (NULL);
	ft_bzero(msg, len);
	cp = msg;
	fill_num(&cp, timestamp);
	*cp++ = ' ';
	fill_num(&cp, philosopher);
	*cp = ' ';
	ft_strcat(msg, action);
	*(msg + len - 2) = '\n';
	return (msg);
}
*/

int	print_action(const struct timeval *start, t_cuint philo, t_cchar *action)
{
	struct timeval	current;
	struct timeval	elapsed;
	//char			*message;
	t_ull			milliseconds;

	if (gettimeofday(&current, NULL) < 0)
		return (EXIT_FAILURE);
	timersub(&current, start, &elapsed);
	milliseconds = elapsed.tv_sec * 1000 + elapsed.tv_usec / 1000;
	/*
	message = concat(milliseconds, philo, action);
	if (! message)
		return (EXIT_FAILURE);
	write(1, message, ft_strlen(message));
	free(message);
	*/
	printf("%llu %u %s\n", milliseconds, philo, action);
	return (EXIT_SUCCESS);
}
