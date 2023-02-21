/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:34:06 by edu               #+#    #+#             */
/*   Updated: 2023/02/21 19:24:40 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	loop_simulation(t_table *table)
{
	pthread_t	*threads;
	int			index;

	threads = ft_calloc(sizeof(pthread_t), table->philos->args->p_quantity);
	index = 0;
	while (index < table->philos[0].args->p_quantity)
	{
		pthread_create(&threads[index], NULL, simulation, &table->philos[index]);
		index++;
	}
	index = 0;
	while (index < table->philos->args->p_quantity)
	{
		pthread_join(threads[index], NULL);
		index++;
	}
	free(threads);
}
