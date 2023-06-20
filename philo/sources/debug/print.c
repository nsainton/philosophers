/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:44:41 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/20 15:51:59 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "philo_int.h"

int	lprint(const char *s, ...)
{
	static pthread_mutex_t	lock;
	va_list					ap;
	int						printed;

	if (! s)
		return (pthread_mutex_init(&lock, NULL));
	if (! *s)
		return (pthread_mutex_destroy(&lock));
	va_start(ap, s);
	pthread_mutex_lock(&lock);
	printed = vprintf(s, ap);
	pthread_mutex_unlock(&lock);
	return (printed);
}
