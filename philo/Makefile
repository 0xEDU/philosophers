NAME = philo
PATH_SRCS = ./sources/
PATH_OBJS = ./objects/

SRCS = main.c

OBJS = ${SRCS:%.c=$(PATH_OBJS)%.o}

INCLUDE = -I ./includes/
FLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJS)
	@cc $(FLAGS) $(OBJS) -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Object creation done!\033[0m"

clean:
	@make clean --no-print-directory -C ./libft/
	@rm -rf $(PATH_OBJ)
	@echo "\33[1;93m[SUCCESS] Objects removed!\33[0m"

fclean: clean
	@rm -f $(NAME)
	@make fclean --no-print-directory -C ./libft/
	@echo "\033[1;93m[SUCCESS] Full clean done!\33[0m"

re: fclean all
	
.PHONY: all clean fclean re
