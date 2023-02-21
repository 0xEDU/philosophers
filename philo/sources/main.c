/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:09 by edu               #+#    #+#             */
/*   Updated: 2023/02/21 19:33:22 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo, time_t sim_start)
{
	t_fork	*first;
	t_fork	*last;

	if (philo->id % 2 == 0)
	{
		first = philo->left_fork;
		last = philo->right_fork;
	}
	else
	{
		first = philo->right_fork;
		last = philo->left_fork;
	}
	pthread_mutex_lock(first);
	printf("%ld Philosopher %d has taken a fork.\n",
		get_elapsed_time(sim_start), philo->id);
	pthread_mutex_lock(last);
	printf("%ld Philosopher %d has taken a fork.\n",
		get_elapsed_time(sim_start), philo->id);
	printf("%ld Philosopher %d is eating. 😋\n",
		get_elapsed_time(sim_start), philo->id);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	usleep(philo->args->p_eat * 1000);
}

void	rest(t_philo *philo, time_t sim_start)
{
	printf("%ld Philosopher %d is sleeping. 😴\n",
		get_elapsed_time(sim_start), philo->id);
	usleep(philo->args->p_sleep * 1000);
}

void	think(t_philo *philo, time_t sim_start)
{
	printf("%ld Philosopher %d is thinking. 🤔\n",
		get_elapsed_time(sim_start), philo->id);
}

void	*simulation(void *philo)
{
	const time_t sim_start = get_current_time();

	eat((t_philo *)philo, sim_start);
	rest((t_philo *)philo, sim_start);
	think((t_philo *)philo, sim_start);
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
