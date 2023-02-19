/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:34:06 by edu               #+#    #+#             */
/*   Updated: 2023/02/19 11:57:43 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	loop_simulation(t_table *table)
{
	pthread_t	thread;
	int			*index;

	index = ft_calloc(sizeof(int), 1);
	*index = 1;
while (*index <= table->args->p_quantity)
	{
		pthread_create(&thread, NULL, simulation, (void *)table);
		pthread_join(thread, NULL);
		(*index)++;
	}
	free(index);
}
