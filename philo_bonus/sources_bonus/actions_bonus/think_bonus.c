/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:54:44 by etachott          #+#    #+#             */
/*   Updated: 2023/03/02 15:58:32 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	think(t_philo *philo, time_t sim_start)
{
	print_state(philo, THINK, sim_start);
	usleep(500);
	return (1);
}
