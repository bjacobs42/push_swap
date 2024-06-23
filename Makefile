NAME	:= push_swap
BONUS	:= checker
LIBFT	:= libft
OBJ_DIR	:= obj/
SRC_DIR	:= src/
INCLUDE	:= -I include -I $(LIBFT)/include
CC		:= gcc

# Reset
NC		= \033[0m# 		Text Reset

# Regular Colors
BLACK	= \033[0;30m#	Black
RED		= \033[0;31m#	Red
GREEN	= \033[1;32m#	Green
YELLOW	= \033[1;33m#	Yellow
BLUE	= \033[1;34m#	Blue
PURPLE	= \033[0;35m#	Purple
BLD_PUR	= \033[1;35m#	Purple but bold
CYAN	= \033[1;36m#	Cyan
WHITE	= \033[1;37m#	White

ifdef DEBUG
	CFLAGS	:= -g -fsanitize=address
else
	CFLAGS	:= -Wall -Werror -Wextra
endif

RADIX_DIR	:= radix_sort/
RADIX_SORT	:= $(RADIX_DIR)radix_sort.c $(RADIX_DIR)radix_utils.c $(RADIX_DIR)toi.c $(RADIX_DIR)shifting.c

SIMPLE_DIR	:= simple_sort/
SIMPLE_SORT	:= $(SIMPLE_DIR)simple_sort.c $(SIMPLE_DIR)try_operations.c

STACK_DIR	:= stack_operations/
STACK_OPER	:= $(STACK_DIR)operations.c $(STACK_DIR)stack_utils.c

GNL_DIR		:= get_next_line/
GNL			:= $(GNL_DIR)get_next_line.c $(GNL_DIR)get_next_line_utils.c

CHECKER_DIR	:= checker/
CHECKER		:= $(CHECKER_DIR)checker_bonus.c $(CHECKER_DIR)operations_bonus.c

ifdef WITH_BONUS
	NAME		:= $(BONUS)
	FILES		+= $(GNL) $(CHECKER) $(STACK_DIR)stack_utils.c
else
	FILES		:= main.c $(RADIX_SORT) $(SIMPLE_SORT) $(STACK_OPER)
endif

FILES 		+= parsing.c create_args.c
SRC_FILES	:= $(addprefix $(SRC_DIR), $(FILES))
OBJ_FILES	:= $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@echo "$(RED)compiling:$(NC)" "$(BLUE)$^$(NC)"
	@$(CC) $(INCLUDE) $(CFLAGS) -c $^ -o $@

$(OBJ_DIR):
	@echo "$(YELLOW)creating folders..."
	@mkdir -p $@
	@mkdir -p $(OBJ_DIR)/$(RADIX_DIR)
	@mkdir -p $(OBJ_DIR)/$(SIMPLE_DIR)
	@mkdir -p $(OBJ_DIR)/$(STACK_DIR)
	@mkdir -p $(OBJ_DIR)/$(CHECKER_DIR)
	@mkdir -p $(OBJ_DIR)/$(GNL_DIR)

$(NAME): $(OBJ_DIR) $(OBJ_FILES)
	@echo "$(PURPLE)============================[$(NC)$(BLD_PUR)$(LIBFT)$(NC)$(PURPLE)]============================$(NC)"
	@make -C $(LIBFT)
	@echo "$(PURPLE)============================[$(NC)$(BLD_PUR)$(NAME)$(NC)$(PURPLE)]============================$(NC)"
	@echo "$(YELLOW)creating $@..."
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT)/libft.a  $(INCLUDE) -o $@
	@echo "$(GREEN)done!$(NC)"

bonus:
	make WITH_BONUS=1 all

debug:
	make WITH_DEBUG=1 all
	make WITH_DEBUG=1 bonus

clean:
	@echo "$(CYAN)cleaning...$(NC)"
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ_DIR)
fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)
	@rm -f $(BONUS)
re: fclean all

.PHONY: all bonus debug clean fclean re
