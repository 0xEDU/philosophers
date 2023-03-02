/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:34 by edu               #+#    #+#             */
/*   Updated: 2023/03/02 16:05:18 by etachott         ###   ########.fr       */
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
	long	sim_start;
}				t_philo;

typedef struct s_table {
	t_philo	*philos;
	t_fork	*forks;
}				t_table;

typedef struct timeval	t_timeval;

/* Structural functions */
t_table		*init_table(char *argv[]);
int			validate_argv(int argc, char *argv[]);
void		free_table(t_table *table);

/* Actions functions */
int			eat(t_philo *philo, time_t sim_start);
int			rest(t_philo *philo, time_t sim_start);
int			think(t_philo *philo, time_t sim_start);

/* Time-related functions */
void		msleep(int time);
time_t		get_current_time(void);
time_t		get_elapsed_time(long int start);

/* Simulation functions */
void		loop_simulation(t_table *table);
void		*monitor(void *arg);
void		*simulation(void *arg);

/* Utils functions */
int			are_philos_full(t_philo *philo);
int			ate_enough(t_philo *philo);
long int	ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
int			ft_isdigit(int c);
void		increase_meals_done(t_philo *philo);
int			is_banquet_over(t_philo *philo);
void		print_state(t_philo *philo, char *state, time_t start_time);
#endif
