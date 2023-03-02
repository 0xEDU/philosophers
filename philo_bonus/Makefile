NAME = philo_bonus
PATH_SRCS = ./sources_bonus/
PATH_TIME_SRCS = ./sources_bonus/time_bonus/
PATH_UTILS = ./sources_bonus/utils_bonus/
PATH_ACTIONS_SRCS = ./sources_bonus/actions_bonus/
PATH_OBJS = ./objects/

SRCS = main_bonus.c \
	   ate_enough_bonus.c \
	   free_table_bonus.c \
	   init_table_bonus.c \
	   loop_simulation_bonus.c \
	   monitor_bonus.c \
	   simulation_bonus.c \
	   validate_argv_bonus.c 

ACTIONS_SRCS = eat_bonus.c \
			   rest_bonus.c \
			   think_bonus.c

TIME_SRCS = get_current_time_bonus.c \
			get_elapsed_time_bonus.c \
			msleep_bonus.c

UTILS = are_philos_full_bonus.c \
		ft_atoi_bonus.c \
		ft_calloc_bonus.c \
		ft_isdigit_bonus.c \
		increase_meals_done_bonus.c \
		is_banquet_over_bonus.c \
		print_state_bonus.c

OBJS = ${SRCS:%.c=$(PATH_OBJS)%.o}
UTILS_OBJS = ${UTILS:%.c=$(PATH_OBJS)%.o}
TIME_OBJS = ${TIME_SRCS:%.c=$(PATH_OBJS)%.o}
ACTIONS_OBJS = ${ACTIONS_SRCS:%.c=$(PATH_OBJS)%.o}

INCLUDE = -I ./includes_bonus/
FLAGS = -Wall -Wextra -Werror -g3
LINKERS = -pthread

all: $(NAME)

$(NAME): $(OBJS) $(UTILS_OBJS) $(TIME_OBJS) $(ACTIONS_OBJS)
	@cc $(FLAGS) $(OBJS) $(UTILS_OBJS) $(TIME_OBJS) $(ACTIONS_OBJS) $(LINKERS) -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Object creation done!\033[0m"

$(PATH_OBJS)%.o: $(PATH_UTILS)%.c
	@mkdir -p $(PATH_OBJS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Object creation done!\033[0m"

$(PATH_OBJS)%.o: $(PATH_TIME_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Object creation done!\033[0m"

$(PATH_OBJS)%.o: $(PATH_ACTIONS_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Object creation done!\033[0m"

clean:
	@rm -rf $(PATH_OBJS)
	@echo "\33[1;93m[SUCCESS] Objects removed!\33[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;93m[SUCCESS] Full clean done!\33[0m"

re: fclean all
	
.PHONY: all clean fclean re
