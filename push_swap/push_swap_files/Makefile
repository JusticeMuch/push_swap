NAME = push_swap

FLAGS = -Wall -Wextra -Werror  -I

CC = gcc -o

SRC= ./src/*.c

INC = ./../includes/

all		:	$(NAME)

$(NAME)		:
			@make -C ./../libft/
			@$(CC) $(NAME) $(SRC) $(FLAGS) $(INC) -L ./../libft/ -lft
			@echo "push_swap compiled"

clean	:
			make clean -C ./../libft/
			rm -rf $(NAME)

fclean	:
			make fclean -C ./../libft/
			rm -rf $(NAME)

re		:	fclean all	
