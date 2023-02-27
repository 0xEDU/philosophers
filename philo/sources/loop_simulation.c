/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:34:06 by edu               #+#    #+#             */
/*   Updated: 2023/02/27 18:33:00 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"
#include <pthread.h>
#include <unistd.h>

static int	get_meals_done(t_philo *philo)
{
	int	meals_done;

	pthread_mutex_lock(&philo->args->meals_lock);
	meals_done = philo->meals_done;
	pthread_mutex_unlock(&philo->args->meals_lock);
	return (meals_done);
}

int	are_philos_full(t_philo *philos)
{
	int	i;
	int	ate;

	ate = 0;
	i = 0;
	while (i < philos->args->p_quantity)
	{
		if (get_meals_done(&philos[i]) == philos->args->p_quantity)
			ate++;
		i++;
	}
	if (ate == philos->args->p_quantity)
		return (1);
	return (0);
}

static long	get_last_meal(t_philo *philo)
{
	long	last_meal;

	pthread_mutex_lock(&philo->args->last_meal_lock);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->args->last_meal_lock);
	return (last_meal);
}

static void	end_banquet(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->last_meal_lock);
	philo->args->banquet_ended = 1;
	pthread_mutex_unlock(&philo->args->last_meal_lock);
}

void	*monitor(void *arg)
{
	const time_t	sim_start = get_current_time();
	long			timenow;
	t_philo			*philos;
	int				i;

	i = 0;
	philos = (t_philo *)arg;
	while (!are_philos_full(philos))
	{
		i = 0;
		while (i < philos->args->p_quantity)
		{
			timenow = get_current_time();
			if (timenow - get_last_meal(&philos[i]) >= philos->args->p_die)
			{
				end_banquet(&philos[i]);
				print_state(&philos[i], DIE, sim_start);
				return (NULL);
			}
			i++;
		}
		usleep(100 * 1000);
	}
	return (NULL);
}

void	loop_simulation(t_table *table)
{
	pthread_t	*threads;
	pthread_t	monitor_thread;
	int			i;

	threads = ft_calloc(sizeof(pthread_t), table->philos->args->p_quantity);
	i = 0;
	while (i < table->philos[0].args->p_quantity)
	{
		pthread_create(&threads[i], NULL, simulation, &table->philos[i]);
		i++;
	}
	i = 0;
	pthread_create(&monitor_thread, NULL, monitor, table->philos);
	while (i < table->philos->args->p_quantity)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	pthread_join(monitor_thread, NULL);
	free(threads);
}
