/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:34:06 by edu               #+#    #+#             */
/*   Updated: 2023/02/17 21:44:21 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	loop_simulation(t_args *args)
{
	pthread_t	thread;
	int			*index;

	index = ft_calloc(sizeof(int), 1);
	*index = 1;
	while (*index <= args->p_quantity)
	{
		pthread_create(&thread, NULL, simulation, (void *)index);
		pthread_join(thread, NULL);
		(*index)++;
	}
	free(index);
}
