/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:56:48 by etachott          #+#    #+#             */
/*   Updated: 2023/03/02 15:56:50 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	pthread_mutex_destroy(&args->last_meal_lock);
	pthread_mutex_destroy(&args->banquet_lock);
}

void	free_table(t_table *table)
{
	free_forks(table->forks, table->philos->args->p_quantity);
	free_locks(table->philos->args);
	free(table->philos->args);
	free(table->philos);
	free(table);
}
