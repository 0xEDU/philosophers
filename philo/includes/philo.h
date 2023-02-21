/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:34 by edu               #+#    #+#             */
/*   Updated: 2023/02/21 19:14:44 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_args {
	int	p_quantity;
	int	p_die;
	int	p_eat;
	int	p_sleep;
	int	p_eat_quantity;
}				t_args;

typedef pthread_mutex_t	t_fork;

typedef struct s_philo {
	t_fork	*left_fork;
	t_fork	*right_fork;
	t_args	*args;
	int		id;
}				t_philo;

typedef struct s_table {
	int		current_philo;
	t_philo	*philos;
	t_fork	*forks;
}				t_table;

typedef struct timeval	t_timeval;

/* Structural functions */
t_table		*init_table(char *argv[]);
int			validate_argv(int argc, char *argv[]);
void		free_table(t_table *table);

/* Time-related functions */
time_t		get_current_time(void);
time_t		get_elapsed_time(long int start);

/* Simulation functions */
void		loop_simulation(t_table *table);
void		*simulation(void *arg);

/* Utils functions */
long int	ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
int			ft_isdigit(int c);
#endif
