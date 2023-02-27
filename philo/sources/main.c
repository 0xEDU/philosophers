/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:09 by edu               #+#    #+#             */
/*   Updated: 2023/02/27 18:36:29 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <pthread.h>
#include <unistd.h>

static void	set_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->last_meal_lock);
	philo->last_meal = get_current_time();
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
	if (philo->args->banquet_ended)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	print_state(philo, TAKE_FORK, sim_start);
	print_state(philo, TAKE_FORK, sim_start);
	print_state(philo, EAT, sim_start);
	set_last_meal(philo);
	if (philo->args->p_eat_quantity != -1)
		increase_meals_done(philo);
	usleep(philo->args->p_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (1);
}

int	rest(t_philo *philo, time_t sim_start)
{
	print_state(philo, SLEEP, sim_start);
	usleep(philo->args->p_sleep * 1000);
	return (1);
}

int	think(t_philo *philo, time_t sim_start)
{
	print_state(philo, THINK, sim_start);
	usleep(500);
	return (1);
}

static int	is_banquet_over(t_philo *philo)
{
	int	end;

	pthread_mutex_lock(&philo->args->banquet_lock);
	end = 0;
	if (philo->args->banquet_ended)
		end = 1;
	pthread_mutex_unlock(&philo->args->banquet_lock);
	return (end);
}

void	*simulation(void *ptr)
{
	const time_t	sim_start = get_current_time();
	t_philo			*philo;

	philo = ptr;
	if (philo-> id % 2 == 0)
		usleep(300 * 1000);
	while (!is_banquet_over(philo))
	{
		eat(philo, sim_start);
		if (philo->meals_done == philo->args->p_eat_quantity)
			break ;
		rest(philo, sim_start);
		think(philo, sim_start);
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
