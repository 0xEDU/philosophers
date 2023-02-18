/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:09 by edu               #+#    #+#             */
/*   Updated: 2023/02/18 14:28:43 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(int *philo_id, long int start)
{
	usleep(10);
	printf("%ld Philosopher %d is eating. 😋\n",
		get_elapsed_time(start), *philo_id);
}

void	rest(int *philo_id, long int start)
{
	usleep(200 * 1000);
	printf("%ld Philosopher %d is sleeping. 😴\n",
		get_elapsed_time(start), *philo_id);
}

void	think(int *philo_id, long int start)
{
	usleep(300 * 1000);
	printf("%ld Philosopher %d is thinking. 🤔\n",
		get_elapsed_time(start), *philo_id);
}

void	*simulation(void *arg)
{
	const time_t	start = get_current_time();
	int				*philo_id;

	philo_id = (int *)arg;
	eat(philo_id, start);
	rest(philo_id, start);
	think(philo_id, start);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_args			*args;

	if (!validate_argv(argc, argv))
		return (1);
	args = init_args(argv);
	loop_simulation(args);
	free(args);
	return (0);
}
