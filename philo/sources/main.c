/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:09 by edu               #+#    #+#             */
/*   Updated: 2023/02/16 20:36:15 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*simulation(void *arg)
{
	long *id;

	id = (long *) arg;
	printf("Thread: %ld\n", *id);
	printf("New thread ;D\n");
	return (NULL);
}

int	main(int argc, char *argv[])
{
	pthread_t	thread;
	int			index;

	if (!validate_argv(argc, argv))
		return (1);
	index = 0;
	while (index++ < 3)
	{
		pthread_create(&thread, NULL, simulation, (void *)&thread);
	}
	printf("Exited!\n");
	return (0);
}
