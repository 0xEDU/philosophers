/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msleep_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <etachott@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:43:35 by etachott          #+#    #+#             */
/*   Updated: 2023/03/02 15:59:01 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	msleep(int time)
{
	long	start_time;

	start_time = get_current_time();
	while ((get_current_time() - start_time) < (long)time)
		usleep(10);
}
