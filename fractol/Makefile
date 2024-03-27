NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRCS = src/main.c
OBJS = $(SRCS:.c=.o)

MINILIBXPATH = ./minilibx-linux/
LIBFTPATH = ./libft/
LIBFT = -L$(LIBFTPATH)
MINILIBX = -L$(MINILIBXPATH) -lmlx -lXext -lX11
PRINTFPATH = ./Printf/
PRINTF = -L$(PRINTFPATH)

all: $(NAME)

$(NAME): $(OBJS)
		make -C $(MINILIBXPATH)
		make -C $(LIBFTPATH)
		make -C $(PRINTFPATH)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PRINTF) -lftprintf $(LIBFT) -lft $(MINILIBX) -lm -lbsd

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFTPATH) -I$(MINILIBXPATH) -I$(PRINTFPATH) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make -C $(MINILIBXPATH) clean
	make -C $(LIBFTPATH) fclean
	make -C $(PRINTFPATH) fclean

re: fclean all
