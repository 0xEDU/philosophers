/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:34 by edu               #+#    #+#             */
/*   Updated: 2023/02/17 19:05:06 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_args {
	int	p_quantity;
	int	p_die;
	int	p_eat;
	int	p_sleep;
	int	p_eat_time;
}				t_args;

t_args		*init_args(char *argv[]);
int			validate_argv(int argc, char *argv[]);

/* Utils functions */
long int	ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
int			ft_isdigit(int c);
#endif
