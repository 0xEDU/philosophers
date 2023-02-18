/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:34:06 by edu               #+#    #+#             */
/*   Updated: 2023/02/18 14:57:42 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	loop_simulation(t_philo *philo)
{
	pthread_t	thread;
	int			*index;

	index = ft_calloc(sizeof(int), 1);
	*index = 1;
	while (*index <= philo->args->p_quantity)
	{
		philo->id = *index;
		pthread_create(&thread, NULL, simulation, (void *)philo);
		pthread_join(thread, NULL);
		(*index)++;
	}
	free(index);
}
