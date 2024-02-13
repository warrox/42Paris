NAME_CLIENT = client
NAME_SERVER = server

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

PRINTFPATH = ./Printf/
PRINTF = $(PRINTFPATH)libftprintf.a
UTILS = minitalk_utils.c

SRCS_SERV = server.c
SRCS_CLIENT = client.c

OBJS_SERV = $(SRCS_SERV:%.c=%.o)
OBJS_CLIENT = $(SRCS_CLIENT:%.c=%.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(PRINTF) $(UTILS)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -L$(PRINTFPATH) -lftprintf -o $(NAME_CLIENT) $(UTILS)

$(NAME_SERVER): $(OBJS_SERV) $(PRINTF) $(UTILS)
	$(CC) $(CFLAGS) $(OBJS_SERV) -L$(PRINTFPATH) -lftprintf -o $(NAME_SERVER) $(UTILS)

$(PRINTF):
	make -C $(PRINTFPATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_SERV) $(OBJS_CLIENT)
	make -C $(PRINTFPATH) clean

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	make -C $(PRINTFPATH) fclean

re: fclean all

.PHONY: all clean fclean re
