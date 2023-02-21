/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:13:46 by edu               #+#    #+#             */
/*   Updated: 2023/02/21 19:24:04 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_args	*init_args(char *argv[])
{
	t_args	*args;

	args = ft_calloc(sizeof(t_args), 1);
	args->p_quantity = ft_atoi(argv[1]);
	args->p_die = ft_atoi(argv[2]);
	args->p_eat = ft_atoi(argv[3]);
	args->p_sleep = ft_atoi(argv[4]);
	if (argv[5])
		args->p_eat_quantity = ft_atoi(argv[5]);
	return (args);
}

static t_fork	*init_forks(int quantity)
{
	t_fork	*forks;
	int		index;

	index = 0;
	forks = ft_calloc(sizeof(t_fork), quantity);
	while (index < quantity)
	{
		pthread_mutex_init(&forks[index], NULL);
		index++;
	}
	return (forks);
}

static t_philo	*init_philos(t_fork *forks, char *argv[])
{
	t_philo	*philos;
	int		index;
	int		quantity;

	index = 0;
	quantity = ft_atoi(argv[1]);
	philos = ft_calloc(sizeof(t_philo), quantity);
	while (index < quantity)
	{
		philos[index].args = init_args(argv);
		philos[index].id = index + 1;
		philos[index].left_fork = &forks[index];
		philos[index].right_fork = &forks[(index + 1) % quantity];
		index++;
	}
	return (philos);
}

t_table	*init_table(char *argv[])
{
	t_table	*table;

	table = ft_calloc(sizeof(t_table), 1);
	table->forks = init_forks(ft_atoi(argv[1]));
	table->philos = init_philos(table->forks, argv);
	return (table);
}
