/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:59:19 by edu               #+#    #+#             */
/*   Updated: 2023/02/21 23:33:03 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philo *philo, char *state, time_t sim_start)
{
	pthread_mutex_lock(&philo->args->state_lock);
	printf("%ld Philosopher %d %s\n", get_elapsed_time(sim_start), philo->id, state);
	pthread_mutex_unlock(&philo->args->state_lock);
}
