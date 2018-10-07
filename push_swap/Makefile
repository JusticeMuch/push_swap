NAME = working

all     :   $(NAME)

$(NAME)     :
			@make -C ./push_swap_files
			@make -C ./checker_files
			@mv ./push_swap_files/push_swap . && mv ./checker_files/checker .

clean   :
			@make clean -C ./push_swap_files  
			@make clean -C ./checker_files
			@make fclean -C ./libft

fclean  :	clean
			@rm -rf checker && rm -rf push_swap

re      :   fclean all
