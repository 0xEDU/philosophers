/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:34:06 by edu               #+#    #+#             */
/*   Updated: 2023/02/22 17:57:26 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	loop_simulation(t_table *table)
{
	pthread_t	*threads;
	int			i;

	threads = ft_calloc(sizeof(pthread_t), table->philos->args->p_quantity);
	i = 0;
	while (i < table->philos[0].args->p_quantity)
	{
		pthread_create(&threads[i], NULL, simulation, &table->philos[i]);
		i++;
	}
	i = 0;
	while (i < table->philos->args->p_quantity)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	free(threads);
}
