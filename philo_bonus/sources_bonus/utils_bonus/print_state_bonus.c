/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:59:19 by edu               #+#    #+#             */
/*   Updated: 2023/03/02 20:37:15 by etachott         ###   ########.fr       */
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

	sem_wait(philo->args->state_lock);
	printf("%ld %s %d %s\n",
		get_elapsed_time(sim_start), str, philo->id, state);
	if (ft_strncmp(state, DIE, 5))
		sem_post(philo->args->state_lock);
}
