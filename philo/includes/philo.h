/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:34 by edu               #+#    #+#             */
/*   Updated: 2023/02/17 23:55:59 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_args {
	int	p_quantity;
	int	p_die;
	int	p_eat;
	int	p_sleep;
	int	p_eat_time;
}				t_args;

typedef struct timeval	t_time;

/* Structural functions */
t_args		*init_args(char *argv[]);
int			validate_argv(int argc, char *argv[]);

/* Simulation functions */
void		loop_simulation(t_args *args);
void		*simulation(void *arg);
long int	get_time_elapsed(t_time *tv_start, t_time *tv_end);

/* Utils functions */
long int	ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
int			ft_isdigit(int c);
#endif
