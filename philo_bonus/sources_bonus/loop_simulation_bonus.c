/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_simulation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:34:06 by edu               #+#    #+#             */
/*   Updated: 2023/03/02 20:36:22 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	start_process(t_philo *philo, pid_t *pid, int (*sim)(t_philo *))
{
	int	exit_status;

	*pid = fork();
	if (*pid == 0)
	{
		exit_status = sim(philo);
		finish_philo(philo->philos, exit_status);
	}
}

static void	join_process(t_philo *philos)
{
	int	index;
	int	exit_status;

	index = 0;
	exit_status = 0;
	while (index < philos->args->p_quantity && exit_status == 0)
	{
		waitpid(-1, &exit_status, 0);
		exit_status = WEXITSTATUS(exit_status);
		index++;
	}
	if (exit_status)
	{
		index = 0;
		while (index < philos->args->p_quantity)
		{
			kill(philos[index].pid, SIGKILL);
			index++;
		}
	}
}

void	loop_simulation(t_table *table)
{
	int			i;

	i = -1;
	while (++i < table->philos->args->p_quantity)
		start_process(&table->philos[i], &table->philos[i].pid, &simulation);
	join_process(table->philos);
}
