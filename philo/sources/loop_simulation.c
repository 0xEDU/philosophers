/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:34:06 by edu               #+#    #+#             */
/*   Updated: 2023/02/17 23:56:58 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	loop_simulation(t_args *args)
{
	pthread_t	thread;
	int			*index;
	struct timeval	tv_start;
	struct timeval	tv_end;

	index = ft_calloc(sizeof(int), 1);
	*index = 1;
	while (*index <= args->p_quantity)
	{
		gettimeofday(&tv_start, NULL);
		pthread_create(&thread, NULL, simulation, (void *)index);
		pthread_join(thread, NULL);
		gettimeofday(&tv_end, NULL);
		printf("TIME = %ld\n", get_time_elapsed(&tv_start, &tv_end));
		(*index)++;
	}
	free(index);
}
