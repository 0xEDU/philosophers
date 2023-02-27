/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ate_enough.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:47:45 by etachott          #+#    #+#             */
/*   Updated: 2023/02/27 16:59:05 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ate_enough(t_philo *philo)
{
	int	is_fed;

	pthread_mutex_lock(&philo->args->meals_lock);	
	is_fed = 0;
	if (philo->meals_done == philo->args->p_eat_quantity)
		is_fed = 1;
	pthread_mutex_unlock(&philo->args->meals_lock);	
	return (is_fed);
}
