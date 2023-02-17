/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:09 by edu               #+#    #+#             */
/*   Updated: 2023/02/17 18:44:00 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	eat(void)
{
	printf("Philosopher is eating.\n");
}

void	sleep(void)
{
	printf("Philosopher is sleeping.\n");
}

void	think(void)
{
	printf("Philosopher is thinking.\n");
}

void	*simulation(void *arg)
{
	(void)arg;
	eat();
	sleep();
	think();
	return (NULL);
}

int	main(int argc, char *argv[])
{
	pthread_t	thread;
	t_args		*args;

	if (!validate_argv(argc, argv))
		return (1);
	args = init_args(argv);
	printf("%p\n", &args);
	pthread_create(&thread, NULL, simulation, NULL);
	pthread_join(thread, NULL);
	return (0);
}
