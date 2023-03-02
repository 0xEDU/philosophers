/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:13:46 by edu               #+#    #+#             */
/*   Updated: 2023/03/02 17:44:26 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static t_args	*init_args(char *argv[])
{
	t_args	*args;

	sem_unlink(STATE_LOCK);
	args = ft_calloc(sizeof(t_args), 1);
	args->p_quantity = ft_atoi(argv[1]);
	args->p_die = ft_atoi(argv[2]);
	args->p_eat = ft_atoi(argv[3]);
	args->p_sleep = ft_atoi(argv[4]);
	args->p_eat_quantity = -1;
	args->state_lock = sem_open(STATE_LOCK, O_CREAT, 0644, 1);
	if (argv[5])
		args->p_eat_quantity = ft_atoi(argv[5]);
	return (args);
}

static t_fork	*init_forks(int quantity)
{
	t_fork	*forks;

	sem_unlink(FORKS);
	forks = sem_open(FORKS, O_CREAT, 0644, quantity);
	return (forks);
}

static t_philo	*init_philos(t_fork **forks, char *argv[])
{
	t_philo	*philos;
	t_args	*args;
	int		index;
	long	sim_start;

	index = 0;
	sim_start = get_current_time();
	args = init_args(argv);
	philos = ft_calloc(sizeof(t_philo), ft_atoi(argv[1]));
	while (index < ft_atoi(argv[1]))
	{
		philos[index].args = args;
		philos[index].id = index + 1;
		philos[index].meals_done = 0;
		philos[index].last_meal = 0;
		philos[index].sim_start = sim_start;
		philos[index].left_fork = *forks;
		philos[index].right_fork = *forks;
		philos[index].forks = *forks;
		philos[index].philos = philos;
		index++;
	}
	return (philos);
}

t_table	*init_table(char *argv[])
{
	t_table	*table;

	table = ft_calloc(sizeof(t_table), 1);
	table->forks = init_forks(ft_atoi(argv[1]));
	table->philos = init_philos(&table->forks, argv);
	return (table);
}
