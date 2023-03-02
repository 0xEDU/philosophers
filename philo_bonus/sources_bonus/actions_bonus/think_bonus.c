/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:54:44 by etachott          #+#    #+#             */
/*   Updated: 2023/03/02 20:01:07 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	wait_for_fork(t_philo *philo)
{
	long	current_time;

	while (*(long *)philo->forks < 2)
	{
		current_time = get_elapsed_time(philo->sim_start);
		if ((current_time - philo->last_meal) > philo->args->p_die)
		{
			print_state(philo, DIE, philo->sim_start);
			finish_philo(philo->philos, 1);
		}
		usleep(10);
	}
}

void	think(t_philo *philo, time_t sim_start)
{
	print_state(philo, THINK, sim_start);
	usleep(500);
	wait_for_fork(philo);
}
