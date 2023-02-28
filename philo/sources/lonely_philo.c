/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lonely_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:33:56 by etachott          #+#    #+#             */
/*   Updated: 2023/02/28 13:17:19 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*lonely_banquet(void *arg)
{
	return (NULL);
}

void	lonely_philo(long time_to_die)
{
	t_philo	*philo;
	t_fork	*fork;
	pthread_t	thread;

	init_philo(philo);
	pthread_create(&thread, NULL, lonely_banquet, philo);
	pthread_join(thread, NULL);
	free_philo(philo);
	free_fork(fork);
}
