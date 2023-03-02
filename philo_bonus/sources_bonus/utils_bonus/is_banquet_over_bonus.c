/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_banquet_over_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:44:56 by etachott          #+#    #+#             */
/*   Updated: 2023/03/02 15:59:36 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_banquet_over(t_philo *philo)
{
	int	end;

	pthread_mutex_lock(&philo->args->banquet_lock);
	end = 0;
	if (philo->args->banquet_ended)
		end = 1;
	pthread_mutex_unlock(&philo->args->banquet_lock);
	return (end);
}
