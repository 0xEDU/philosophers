/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ate_enough_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:56:15 by etachott          #+#    #+#             */
/*   Updated: 2023/03/02 15:56:16 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo_bonus.h"

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
