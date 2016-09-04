CC = gcc
CFLAG = -Wall -Wextra -Werror
CHECK_DIR = check_dir
SWAP_DIR = swap_dir
LIB = libft/libft.a ft_printf/libftprintf.a

.PHONY: re clean fclean all checker push_swap

all: $(LIB) checker push_swap

%.a:
	@make -C $(dir $@)

clean_lib:
	@make fclean -C libft
	@make fclean -C ft_printf

checker:
	@make -C $(CHECK_DIR)

push_swap:
	@make -C $(SWAP_DIR)

clean:
	@make clean -C $(CHECK_DIR)
	@make clean -C $(SWAP_DIR)

fclean: clean_lib
	@make fclean -C $(CHECK_DIR)
	@make fclean -C $(SWAP_DIR)

re: fclean all
