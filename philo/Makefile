NAME = philo
PATH_SRCS = ./sources/
PATH_TIME_SRCS = ./sources/time/
PATH_UTILS = ./sources/utils/
PATH_ACTIONS_SRCS = ./sources/actions/
PATH_OBJS = ./objects/

SRCS = main.c \
	   ate_enough.c \
	   free_table.c \
	   init_table.c \
	   loop_simulation.c \
	   monitor.c \
	   simulation.c \
	   validate_argv.c 

ACTIONS_SRCS = eat.c \
			   rest.c \
			   think.c

TIME_SRCS = get_current_time.c \
			get_elapsed_time.c \
			msleep.c

UTILS = are_philos_full.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_isdigit.c \
		increase_meals_done.c \
		is_banquet_over.c \
		print_state.c

OBJS = ${SRCS:%.c=$(PATH_OBJS)%.o}
UTILS_OBJS = ${UTILS:%.c=$(PATH_OBJS)%.o}
TIME_OBJS = ${TIME_SRCS:%.c=$(PATH_OBJS)%.o}
ACTIONS_OBJS = ${ACTIONS_SRCS:%.c=$(PATH_OBJS)%.o}

INCLUDE = -I ./includes/
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
