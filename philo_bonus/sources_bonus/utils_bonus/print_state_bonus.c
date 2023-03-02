/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:59:19 by edu               #+#    #+#             */
/*   Updated: 2023/03/02 16:00:10 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && i < (n - 1))
	{
		if (s1[i] == '\0')
			break ;
		i++;
	}
	return (((unsigned char) s1[i]) - ((unsigned char) s2[i]));
}

void	print_state(t_philo *philo, char *state, time_t sim_start)
{
	const char	*str = "Philosopher";

	pthread_mutex_lock(&philo->args->state_lock);
	if (is_banquet_over(philo) && ft_strncmp(state, DIE, 5))
	{
		pthread_mutex_unlock(&philo->args->state_lock);
		return ;
	}
	printf("%ld %s %d %s\n",
		get_elapsed_time(sim_start), str, philo->id, state);
	pthread_mutex_unlock(&philo->args->state_lock);
}
