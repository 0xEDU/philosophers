/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:47:18 by etachott          #+#    #+#             */
/*   Updated: 2023/03/02 15:58:23 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	set_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->last_meal_lock);
	philo->last_meal = get_elapsed_time(philo->sim_start);
	pthread_mutex_unlock(&philo->args->last_meal_lock);
}

static void	take_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}
}

int	eat(t_philo *philo, time_t sim_start)
{
	take_forks(philo);
	if (is_banquet_over(philo))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	print_state(philo, TAKE_FORK, sim_start);
	print_state(philo, TAKE_FORK, sim_start);
	print_state(philo, EAT, sim_start);
	set_last_meal(philo);
	msleep(philo->args->p_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	if (philo->args->p_eat_quantity != -1)
		increase_meals_done(philo);
	return (1);
}
