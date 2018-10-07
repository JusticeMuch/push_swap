NAME = checker

FLAGS = -Wall -Wextra -Werror -I

CC = clang -o

SRC= ./src/*.c

INC = ./../includes/

all		:	$(NAME)

$(NAME)		:
			@make -C ./../libft/
			@$(CC) $(NAME) $(SRC) $(FLAGS) $(INC) -L ./../libft/ -lft
			@echo "checker compiled"

clean	:
			make clean -C ./../libft/
			rm -rf $(NAME)

fclean	:
			make fclean -C ./../libft/
			rm -rf $(NAME)

re		:	fclean all	
