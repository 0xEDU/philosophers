/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:09 by edu               #+#    #+#             */
/*   Updated: 2023/02/28 23:19:01 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <pthread.h>
#include <unistd.h>

void	msleep(int time)
{
	long	start_time;

	start_time = get_current_time();
	while ((get_current_time() - start_time) < (long)time)
		usleep(10);
}

int	is_banquet_over(t_philo *philo)
{
	int	end;

	pthread_mutex_lock(&philo->args->banquet_lock);
	end = 0;
	if (philo->args->banquet_ended)
		end = 1;
	pthread_mutex_unlock(&philo->args->banquet_lock);
	return (end);
}

static void	set_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->last_meal_lock);
	philo->last_meal = get_elapsed_time(philo->sim_start);
	pthread_mutex_unlock(&philo->args->last_meal_lock);
}

int	eat(t_philo *philo, time_t sim_start)
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

int	rest(t_philo *philo, time_t sim_start)
{
	print_state(philo, SLEEP, sim_start);
	msleep(philo->args->p_sleep);
	return (1);
}

int	think(t_philo *philo, time_t sim_start)
{
	print_state(philo, THINK, sim_start);
	usleep(500);
	return (1);
}

static void *eat_alone(t_philo *philo, time_t sim_start)
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

int	main(int argc, char *argv[])
{
	t_table	*table;

	if (!validate_argv(argc, argv))
		return (1);
	table = init_table(argv);
	loop_simulation(table);
	free_table(table);
	return (0);
}
