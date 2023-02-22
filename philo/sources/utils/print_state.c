/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:59:19 by edu               #+#    #+#             */
/*   Updated: 2023/02/22 17:26:05 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philo *philo, char *state, time_t sim_start)
{
	const char	*str = "Philosopher";

	pthread_mutex_lock(&philo->args->state_lock);
	printf("%ld %s %d %s\n",
		get_elapsed_time(sim_start), str, philo->id, state);
	pthread_mutex_unlock(&philo->args->state_lock);
}
