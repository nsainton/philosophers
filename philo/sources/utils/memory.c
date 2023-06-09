/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:21:52 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/09 16:23:19 by nsainton         ###   ########.fr       */
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
