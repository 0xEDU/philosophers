/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_philo_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:44:56 by etachott          #+#    #+#             */
/*   Updated: 2023/03/02 19:44:27 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	finish_philo(t_philo *philos, int exit_status)
{
	sem_close(philos->forks);
	sem_close(philos->args->state_lock);
	sem_unlink(STATE_LOCK);
	sem_unlink(FORKS);
	free(philos);
	exit(exit_status);
}
