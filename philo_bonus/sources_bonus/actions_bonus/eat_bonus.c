/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:47:18 by etachott          #+#    #+#             */
/*   Updated: 2023/03/02 19:55:42 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat(t_philo *philo, time_t sim_start)
{
	sem_wait(philo->right_fork);
	sem_wait(philo->left_fork);
	print_state(philo, TAKE_FORK, sim_start);
	print_state(philo, TAKE_FORK, sim_start);
	print_state(philo, EAT, sim_start);
	philo->last_meal = get_elapsed_time(philo->sim_start);
	am_i_dead_yet(philo, philo->args->p_eat);
	sem_post(philo->right_fork);
	sem_post(philo->left_fork);
	philo->meals_done++;
}
