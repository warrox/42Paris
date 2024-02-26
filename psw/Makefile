NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRCS = src/main.c src/psw_utils.c src/parser.c \
       src/psw_utils_1.c src/psw_utils_2.c src/ft_split.c \
	   src/ft_itoa.c src/algo_sort.c src/psw_utils_3.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
