/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_simulation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:34:06 by edu               #+#    #+#             */
/*   Updated: 2023/03/02 15:57:35 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	loop_simulation(t_table *table)
{
	pthread_t	*threads;
	pthread_t	monitor_thread;
	int			i;

	threads = ft_calloc(sizeof(pthread_t), table->philos->args->p_quantity);
	i = 0;
	while (i < table->philos->args->p_quantity)
	{
		pthread_create(&threads[i], NULL, simulation, &table->philos[i]);
		i++;
	}
	i = 0;
	pthread_create(&monitor_thread, NULL, monitor, table->philos);
	while (i < table->philos->args->p_quantity)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	pthread_join(monitor_thread, NULL);
	free(threads);
}
