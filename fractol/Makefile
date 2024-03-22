NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRCS = src/main.c
OBJS = $(SRCS:.c=.o)

MINILIBXPATH = ./minilibx-linux/
MINILIBX = -L$(MINILIBXPATH) -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS)
		make -C $(MINILIBXPATH)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MINILIBX) -lm -lbsd

%.o: %.c
	$(CC) $(CFLAGS) -I$(MINILIBXPATH) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make -C $(MINILIBXPATH) clean

re: fclean all
