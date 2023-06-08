/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:24:55 by nsainton          #+#    #+#             */
/*   Updated: 2023/06/08 16:29:04 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_strchr(const char *str, const int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str ++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (*(str + index))
		index ++;
	return (index);
}
