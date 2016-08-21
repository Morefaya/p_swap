CC = gcc
CFLAG = -Wall -Wextra -Werror
SRC = main.c lst_tab2d.c print_lst.c swap.c push.c rotate.c rev_rotate.c\
bubble_sort.c danm_sort.c lst_average.c lst_median.c check_asc.c uni_sort.c\
check_asc_rot.c snd_step.c check_prev.c check_next.c get_highest.c get_lowest.c\
turn_list.c check_prevnext.c asc_sort.c where_is.c hard_sort.c\
swaping_sort.c end_push.c main_sort.c del_content.c quick_sort.c lst_trans.c\
jc_sort.c get_next.c get_prev.c get_higher.c get_lower.c count_low.c count_high.c\
range_sort_asc.c range_sort_dsc.c
SRC_DIR = ./src
SRC_C = $(patsubst %, $(SRC_DIR)/%, $(SRC))
OBJ = $(SRC:.c=.o)
OBJ_DIR = ./obj
OBJ_O = $(patsubst %, $(OBJ_DIR)/%, $(OBJ))
HDIR = include
LIB = ../libft/libft.a
L_H = -L ../libft -lft
FILE = 
NAME = ../push_swap
.PHONY: re run rr clean fclean all

all: $(LIB) $(NAME)

%.a:
	@make -C $(dir $@)

clean_lib:
	@make fclean -C ../libft

$(NAME): $(OBJ_DIR) $(OBJ_O)
	@$(CC) -o $@ -I $(HDIR) $(L_H) $(OBJ_O) $(CFLAG)
	@echo "\033[32mpush_swap done\033[0m"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $< -o $@ -I $(HDIR) $(CFLAG)

clean:
	@rm -rf $(OBJ_O)
	@echo "\033[31mobject files removed\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo "\033[31mpush_swap deleted\033[0m"

re: fclean all

run:
	@./$(NAME) $(FILE) | cat -e

rr: re run
