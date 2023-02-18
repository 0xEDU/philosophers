/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:09 by edu               #+#    #+#             */
/*   Updated: 2023/02/18 15:03:02 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	usleep(10);
	printf("%ld Philosopher %d is eating. 😋\n",
		get_elapsed_time(philo->time_start), philo->id);
}

void	rest(t_philo *philo)
{
	usleep(200 * 1000);
	printf("%ld Philosopher %d is sleeping. 😴\n",
		get_elapsed_time(philo->time_start), philo->id);
}

void	think(t_philo *philo)
{
	usleep(300 * 1000);
	printf("%ld Philosopher %d is thinking. 🤔\n",
		get_elapsed_time(philo->time_start), philo->id);
}

void	*simulation(void *philo)
{
	((t_philo *) philo)->time_start = get_current_time();
	eat(philo);
	rest(philo);
	think(philo);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_philo			*philo;

	if (!validate_argv(argc, argv))
		return (1);
	philo = ft_calloc(sizeof(t_philo), 1);
	philo->args = init_args(argv);
	loop_simulation(philo);
	free(philo->args);
	free(philo);
	return (0);
}
