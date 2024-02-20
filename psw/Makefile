NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c psw_utils.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
