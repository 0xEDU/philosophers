/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:56:02 by etachott          #+#    #+#             */
/*   Updated: 2023/03/02 19:43:44 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	am_i_dead_yet(t_philo *philo, int ms_time)
{
	long	current_time;
	long	start_time;

	start_time = get_current_time();
	while (get_current_time() - start_time < (long)ms_time)
	{
		usleep(10);
		current_time = 	get_elapsed_time(philo->sim_start);
		if ((current_time - philo->last_meal) > philo->args->p_die)
		{
			print_state(philo, DIE, philo->sim_start);
			finish_philo(philo->philos, 1);
		}
	}
}

static void	*eat_alone(t_philo *philo, time_t sim_start)
{
	sem_wait(philo->left_fork);
	print_state(philo, TAKE_FORK, philo->sim_start);
	am_i_dead_yet(philo, philo->args->p_die);
	msleep(1);
	print_state(philo, DIE, philo->sim_start);
	finish_philo(philo->philos, 1);
	return (NULL);
}

int	simulation(t_philo *philo)
{
	int		exit_status;

	if (philo->id % 2 == 0)
		msleep(5);
	if (philo->args->p_quantity == 1)
		eat_alone(philo, philo->sim_start);
	while (1)
	{
		eat(philo, philo->sim_start);
		if (philo->meals_done == philo->args->p_eat_quantity)
			finish_philo(philo->philos, 0);
		rest(philo, philo->sim_start);
		think(philo, philo->sim_start);
	}
	return (0);
}
