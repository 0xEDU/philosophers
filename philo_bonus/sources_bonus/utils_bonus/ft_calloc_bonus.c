/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:47:16 by coder             #+#    #+#             */
/*   Updated: 2023/03/02 15:59:22 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = 0;
	if (!size || !count)
		return (malloc(0));
	if (size > 2147483647 / count)
		return (NULL);
	p = malloc(count * size);
	if (p == NULL)
		return (p);
	while (i < size * count)
		p[i++] = '\0';
	return (p);
}
