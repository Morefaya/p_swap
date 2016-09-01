CC = gcc
CFLAG = -Wall -Wextra -Werror
SRC = main.c strisnbr.c double_val.c max_int.c check_nbr.c print_op.c get_op_lst.c\
lst_inttab.c print_lst.c del_content.c do_allop.c do_op.c push.c rotate.c swap.c\
rev_rotate.c check_asc.c get_option.c del_op.c count_arg.c operate.c
SRC_DIR = ./src
SRC_C = $(patsubst %, $(SRC_DIR)/%, $(SRC))
OBJ = $(SRC:.c=.o)
OBJ_DIR = ./obj
OBJ_O = $(patsubst %, $(OBJ_DIR)/%, $(OBJ))
HDIR = include
LIB = ../libft/libft.a
L_H = -L ../libft -lft
FILE = 
NAME = ../checker
.PHONY: re run rr clean fclean all

all: $(LIB) $(NAME)

%.a:
	@make -C $(dir $@)

clean_lib:
	@make fclean -C ../libft

$(NAME): $(OBJ_DIR) $(OBJ_O)
	@$(CC) -o $@ -I $(HDIR) $(L_H) $(OBJ_O) $(CFLAG)
	@echo "\033[32mchecker done\033[0m"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $< -o $@ -I $(HDIR) $(CFLAG)

clean:
	@rm -rf $(OBJ_O)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)

re: fclean all

run:
	@./$(NAME) $(FILE) | cat -e

rr: re run
