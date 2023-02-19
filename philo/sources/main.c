/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:09 by edu               #+#    #+#             */
/*   Updated: 2023/02/19 12:02:20 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_table *table)
{
	printf("%ld Philosopher %d is eating. 😋\n",
		get_elapsed_time(table->sim_start), table->philos->id);
	usleep(table->args->p_eat * 1000);
}

void	rest(t_table *table)
{
	printf("%ld Philosopher %d is sleeping. 😴\n",
		get_elapsed_time(table->sim_start), table->philos->id);
	usleep(table->args->p_sleep * 1000);
}

void	think(t_table *table)
{
	printf("%ld Philosopher %d is thinking. 🤔\n",
		get_elapsed_time(table->sim_start), table->philos->id);
}

void	*simulation(void *table)
{
	((t_table *) table)->sim_start = get_current_time();
	eat(table);
	rest(table);
	think(table);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_table	*table;

	if (!validate_argv(argc, argv))
		return (1);
	table = init_table(argv);
	loop_simulation(table);
	free_table(table);
	return (0);
}
