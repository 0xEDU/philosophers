/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:22:02 by edu               #+#    #+#             */
/*   Updated: 2023/02/18 13:56:53 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_current_time(void)
{
	t_timeval	timeval;

	gettimeofday(&timeval, NULL);
	return (((timeval.tv_sec * 1000000) + timeval.tv_usec) / 1000);
}
