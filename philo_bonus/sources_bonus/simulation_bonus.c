/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:56:02 by etachott          #+#    #+#             */
/*   Updated: 2023/03/02 15:57:52 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*eat_alone(t_philo *philo, time_t sim_start)
{
	pthread_mutex_lock(philo->left_fork);
	print_state(philo, TAKE_FORK, sim_start);
	pthread_mutex_unlock(philo->left_fork);
	return (NULL);
}

void	*simulation(void *ptr)
{
	t_philo			*philo;

	philo = ptr;
	if (philo->id % 2 == 0)
		msleep(5);
	if (philo->args->p_quantity == 1)
		return (eat_alone(philo, philo->sim_start));
	while (!is_banquet_over(philo))
	{
		eat(philo, philo->sim_start);
		if (philo->meals_done == philo->args->p_eat_quantity)
			return (NULL);
		rest(philo, philo->sim_start);
		think(philo, philo->sim_start);
	}
	return (NULL);
}
