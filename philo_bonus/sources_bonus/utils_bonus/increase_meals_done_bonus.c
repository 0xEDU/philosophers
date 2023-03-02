/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_meals_done_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:39:03 by etachott          #+#    #+#             */
/*   Updated: 2023/03/02 15:59:31 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	increase_meals_done(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->meals_lock);
	philo->meals_done++;
	pthread_mutex_unlock(&philo->args->meals_lock);
}
