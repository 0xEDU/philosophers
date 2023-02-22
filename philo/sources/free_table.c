/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:58:31 by edu               #+#    #+#             */
/*   Updated: 2023/02/22 17:42:04 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_forks(t_fork *forks, int quantity)
{
	int	index;

	index = 0;
	while (index < quantity)
	{
		pthread_mutex_destroy(&forks[index]);
		index++;
	}
	free(forks);
}

static void	free_locks(t_args *args)
{
	pthread_mutex_destroy(&args->state_lock);
	pthread_mutex_destroy(&args->meals_lock);
}

void	free_table(t_table *table)
{
	free_forks(table->forks, table->philos->args->p_quantity);
	free_locks(table->philos->args);
	free(table->philos->args);
	free(table->philos);
	free(table);
}
