/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:13:46 by edu               #+#    #+#             */
/*   Updated: 2023/02/18 15:16:34 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_args	*init_args(char *argv[])
{
	t_args	*new;

	new = ft_calloc(sizeof(t_args), 1);
	new->p_quantity = ft_atoi(argv[1]);
	new->p_die = ft_atoi(argv[2]);
	new->p_eat = ft_atoi(argv[3]);
	new->p_sleep = ft_atoi(argv[4]);
	if (argv[5])
		new->p_eat_quantity = ft_atoi(argv[5]);
	return (new);
}
