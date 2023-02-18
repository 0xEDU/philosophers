NAME = philo
PATH_SRCS = ./sources/
PATH_UTILS = ./sources/utils/
PATH_OBJS = ./objects/

SRCS = main.c \
	   init_args.c \
	   loop_simulation.c \
	   validate_argv.c 

UTILS = ft_atoi.c \
		ft_calloc.c \
		ft_isdigit.c

OBJS = ${SRCS:%.c=$(PATH_OBJS)%.o}
UTILS_OBJS = ${UTILS:%.c=$(PATH_OBJS)%.o}

INCLUDE = -I ./includes/
FLAGS = -Wall -Wextra -Werror -g3
LINKERS = -pthread

all: $(NAME)

$(NAME): $(OBJS) $(UTILS_OBJS)
	@cc $(FLAGS) $(OBJS) $(UTILS_OBJS) $(LINKERS) -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Object creation done!\033[0m"

$(PATH_OBJS)%.o: $(PATH_UTILS)%.c
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
