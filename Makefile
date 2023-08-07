# -------------------------------COLORS-------------------------------

RED = \033[0;31m
GREEN = \033[0;32m
PURPLE = \033[1;35m
RESET = \033[0m

# ------------------------------VARIABLES------------------------------

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f
MAKE = make --no-print-directory -C

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = srcs/1_main.c \
		srcs/2_args_validation.c \
		srcs/3_stack_init.c \
		srcs/4_sort.c \
		srcs/5_sort_utils_0.c \
		srcs/6_sort_utils_1.c \
		srcs/7_sort_utils_2.c \
		srcs/8_utils.c \
		operations/push.c \
		operations/reverse.c \
		operations/rotate.c \
		operations/swap.c

S_OBJS = $(SRCS:.c=.o)

BONUS_SRCS =
B_OBJS = $(BONUS_SRCS:.c=.o)

# -------------------------------RULES---------------------------------

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(S_OBJS)
	@$(MAKE) $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	@printf "$(GREEN)	Executable ./$(NAME) was created.\n$(RESET)"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I.
	@printf "$(PURPLE)	Compiled$(RESET) $<\n"

clean:
	@$(MAKE) $(LIBFT_DIR) clean
	@$(RM) $(S_OBJS)
	@printf "$(RED)	Object files were removed.\n$(RESET)"

fclean: clean
	@$(MAKE) $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@printf "$(RED)	Executable ./$(NAME) was removed.\n$(RESET)"

re: fclean all
