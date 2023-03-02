/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:56:48 by etachott          #+#    #+#             */
/*   Updated: 2023/03/02 20:12:36 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_table(t_table *table)
{
	sem_close(table->forks);
	sem_close(table->philos->args->state_lock);
	sem_unlink(FORKS);
	sem_unlink(STATE_LOCK);
	free(table->philos);
	free(table);
}
