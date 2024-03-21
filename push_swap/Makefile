NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRCS = src/main.c src/psw_utils.c src/parser.c \
       src/psw_utils_1.c src/psw_utils_2.c src/ft_split.c \
       src/ft_itoa.c src/algo_sort.c src/psw_utils_3.c src/algo_small.c \
	   src/is_sorted.c src/algo_sort_utils_1.c src/algo_sort_utils_2.c \
	   src/algo_sort_utils_3.c src/algo_sort_utils_4.c src/algo_sort_utils_5.c \
	   src/psw_utils_4.c
OBJS = $(SRCS:%.c=%.o)

PRINTFPATH = ./Printf/
PRINTF = $(PRINTFPATH)libftprintf.a

all: $(NAME)

$(NAME): $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) -L$(PRINTFPATH) -lftprintf  -o $(NAME)

$(PRINTF):
	make -C $(PRINTFPATH)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
	rm -f $(PRINTF)

fclean: clean
	rm -f $(NAME)
	rm -f $(PRINTF)
re: fclean all

