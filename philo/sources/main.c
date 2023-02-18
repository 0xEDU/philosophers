/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:09 by edu               #+#    #+#             */
/*   Updated: 2023/02/18 00:08:38 by edu              ###   ########.fr       */
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

long int	get_time_elapsed(t_time *tv_start, t_time *tv_end)
{
	long int		elapsed_sec;
	long int		elapsed_usec;

	elapsed_sec = tv_end->tv_sec - tv_start->tv_sec;
	elapsed_usec = tv_end->tv_usec - tv_start->tv_usec;
	if (elapsed_usec < 0)
	{
		elapsed_sec--;
		elapsed_usec += 1000000;
	}
	return (((elapsed_sec * 1000) + elapsed_usec) / 1000);
}

long int	get_time(void)
{
	t_time			t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000000 + t.tv_usec);
}

int	main(int argc, char *argv[])
{
	t_args			*args;
	long int		p;

	p = get_time();
	if (!validate_argv(argc, argv))
		return (1);
	args = init_args(argv);
	loop_simulation(args);
	free(args);
	printf("%ld\n", get_time() - p);
	return (0);
}
