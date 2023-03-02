/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:54:15 by etachott          #+#    #+#             */
/*   Updated: 2023/03/02 15:58:28 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	rest(t_philo *philo, time_t sim_start)
{
	print_state(philo, SLEEP, sim_start);
	msleep(philo->args->p_sleep);
	return (1);
}
