/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:34 by edu               #+#    #+#             */
/*   Updated: 2023/02/27 18:32:16 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define TAKE_FORK "has taken a fork."
# define EAT "is eating."
# define SLEEP "is sleeping."
# define THINK "is thinking."
# define DIE "died."

typedef pthread_mutex_t	t_fork;

typedef struct s_args {
	int		p_quantity;
	int		p_die;
	int		p_eat;
	int		p_sleep;
	int		p_eat_quantity;
	int		banquet_ended;
	t_fork	state_lock;
	t_fork	meals_lock;
	t_fork	last_meal_lock;
	t_fork	banquet_lock;
}				t_args;

typedef struct s_philo {
	t_fork	*left_fork;
	t_fork	*right_fork;
	t_args	*args;
	int		id;
	long	last_meal;
	int		meals_done;
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
int			ate_enough(t_philo *philo);
long int	ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
int			ft_isdigit(int c);
void		print_state(t_philo *philo, char *state, time_t start_time);
void		increase_meals_done(t_philo *philo);
#endif
