/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_i_dead_yet_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:02:28 by etachott          #+#    #+#             */
/*   Updated: 2023/03/02 20:41:30 by etachott         ###   ########.fr       */
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
		current_time = get_elapsed_time(philo->sim_start);
		if ((current_time - philo->last_meal) > philo->args->p_die)
		{
			print_state(philo, DIE, philo->sim_start);
			finish_philo(philo->philos, 1);
		}
	}
}
