NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRCS = 	cost_target.c error_free.c main.c \
		parse_check.c rev_rotate_op.c rotate_op.c \
		sorting.c stack_utils.c swap_push_op.c utils.c \

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

INCLUDE =  -L $(LIBFT_PATH) -lft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@cc $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJS) $(INCLUDE)

$(LIBFT):
	@make -C $(LIBFT_PATH)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re