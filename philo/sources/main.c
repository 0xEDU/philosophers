/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:09 by edu               #+#    #+#             */
/*   Updated: 2023/02/22 18:02:05 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <pthread.h>
#include <unistd.h>

void	eat(t_philo *philo, time_t sim_start)
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
	print_state(philo, TAKE_FORK, sim_start);
	print_state(philo, TAKE_FORK, sim_start);
	print_state(philo, EAT, sim_start);
	if (philo->args->p_eat_quantity != -1)
		increase_meals_done(philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	usleep(philo->args->p_eat * 1000);
}

void	rest(t_philo *philo, time_t sim_start)
{
	print_state(philo, SLEEP, sim_start);
	usleep(philo->args->p_sleep * 1000);
}

void	think(t_philo *philo, time_t sim_start)
{
	print_state(philo, THINK, sim_start);
	usleep(500);
}

void	*simulation(void *ptr)
{
	const time_t	sim_start = get_current_time();
	t_philo			*philo;

	philo = ptr;
	while (philo->meals_done < philo->args->p_eat_quantity)
	{
		if (philo-> id % 2 == 0)
			usleep(300 * 1000);
		eat(philo, sim_start);
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
