/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:09 by edu               #+#    #+#             */
/*   Updated: 2023/02/17 21:46:17 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(int *philo_id)
{
	printf("Philosopher %d is eating.\n", *philo_id);
}

void	sleep(int *philo_id)
{
	printf("Philosopher %d is sleeping.\n", *philo_id);
}

void	think(int *philo_id)
{
	printf("Philosopher %d is thinking.\n", *philo_id);
}

void	*simulation(void *arg)
{
	int	*philo_id;

	philo_id = (int *)arg;
	eat(philo_id);
	sleep(philo_id);
	think(philo_id);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_args		*args;

	if (!validate_argv(argc, argv))
		return (1);
	args = init_args(argv);
	loop_simulation(args);
	free(args);
	return (0);
}
