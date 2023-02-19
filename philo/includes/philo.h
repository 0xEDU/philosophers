/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:34 by edu               #+#    #+#             */
/*   Updated: 2023/02/19 12:02:39 by edu              ###   ########.fr       */
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

typedef struct s_fork_pair {
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
}				t_fork_pair;

typedef struct s_philo {
	t_fork_pair	*forks;
	int			id;
}				t_philo;

typedef struct s_table {
	time_t		sim_start;
	t_args		*args;
	t_philo		*philos;
	t_fork_pair	*forks;
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
