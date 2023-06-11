/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:21:52 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/11 14:13:01 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_bzero(void *s, size_t n)
{
	char	*zone;

	zone = (char *)s;
	while (n-- > 0)
		*(zone + n) = 0;
}

void	ft_memset(void *s, t_cint c, size_t n)
{
	char	*zone;

	zone = (char *)s;
	while (n-- > 0)
		*(zone + n) = c;
}

void	ft_memcpy(void *dest, const void *src, const size_t n)
{
	size_t	index;
	char	*destination;
	char	*source;

	destination = (char *)dest;
	source = (char *)src;
	index = 0;
	while (index < n)
	{
		*(destination + index) = *(source + index);
		index ++;
	}
}
