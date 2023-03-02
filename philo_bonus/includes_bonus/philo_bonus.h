/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott < etachott@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:02:34 by edu               #+#    #+#             */
/*   Updated: 2023/03/02 20:40:59 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <stdio.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define TAKE_FORK "has taken a fork."
# define EAT "is eating."
# define SLEEP "is sleeping."
# define THINK "is thinking."
# define DIE "died."
# define STATE_LOCK "/state_lock"
# define FORKS "/forks"

typedef sem_t	t_fork;

typedef struct s_args {
	int		p_quantity;
	int		p_die;
	int		p_eat;
	int		p_sleep;
	int		p_eat_quantity;
	int		banquet_ended;
	sem_t	*state_lock;
}				t_args;

typedef struct s_philo {
	struct s_philo	*philos;
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_fork			*forks;
	t_args			*args;
	pid_t			pid;
	int				id;
	long			last_meal;
	int				meals_done;
	long			sim_start;
}				t_philo;

typedef struct s_table {
	t_philo	*philos;
	t_fork	*forks;
}				t_table;

/* Structural functions */
t_table		*init_table(char *argv[]);
void		free_table(t_table *table);
int			validate_argv(int argc, char *argv[]);

/* Actions functions */
void		eat(t_philo *philo, time_t sim_start);
void		rest(t_philo *philo, time_t sim_start);
void		think(t_philo *philo, time_t sim_start);

/* Time-related functions */
void		am_i_dead_yet(t_philo *philo, int ms_time);
void		msleep(int time);
time_t		get_current_time(void);
time_t		get_elapsed_time(long int start);

/* Simulation functions */
void		loop_simulation(t_table *table);
void		*monitor(void *arg);
int			simulation(t_philo *philo);

/* Utils functions */
int			are_philos_full(t_philo *philo);
int			ate_enough(t_philo *philo);
int			finish_philo(t_philo *philos, int exit_status);
long int	ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
int			ft_isdigit(int c);
void		increase_meals_done(t_philo *philo);
void		print_state(t_philo *philo, char *state, time_t start_time);
#endif
