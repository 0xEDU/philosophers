/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:09 by edu               #+#    #+#             */
/*   Updated: 2023/02/18 14:49:06 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo, time_t start)
{
	usleep(10);
	printf("%ld Philosopher %d is eating. 😋\n",
		get_elapsed_time(start), philo->id);
}

void	rest(t_philo *philo, time_t start)
{
	usleep(200 * 1000);
	printf("%ld Philosopher %d is sleeping. 😴\n",
		get_elapsed_time(start), philo->id);
}

void	think(t_philo *philo, time_t start)
{
	usleep(300 * 1000);
	printf("%ld Philosopher %d is thinking. 🤔\n",
		get_elapsed_time(start), philo->id);
}

void	*simulation(void *philo)
{
	const time_t	start = get_current_time();

	eat((t_philo *)philo, start);
	rest((t_philo *)philo, start);
	think((t_philo *)philo, start);
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
