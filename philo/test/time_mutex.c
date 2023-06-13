/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 07:58:48 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/13 08:01:26 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

int	main(void)
{
	int				i;
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);
	i = 0;
	while (i < 1000000)
	{
		pthread_mutex_lock(&mutex);
		i ++;
		pthread_mutex_unlock(&mutex);
	}
	pthread_mutex_destroy(&mutex);
	return (0);
}
