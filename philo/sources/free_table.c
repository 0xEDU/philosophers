/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:58:31 by edu               #+#    #+#             */
/*   Updated: 2023/02/19 12:05:16 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_forks(t_fork_pair *forks, int quantity)
{
	int	index;

	index = 0;
	while (index < quantity)
	{
		pthread_mutex_destroy(&forks[index].left_fork);
		pthread_mutex_destroy(&forks[index].right_fork);
		index++;
	}
	free(forks);
}

void	free_table(t_table *table)
{
	free_forks(table->forks, table->args->p_quantity);
	free(table->args);
	free(table->philos);
	free(table);
}
