# Nom de la cible finale
NAME = minitalk.a

# Compilateur
CC = cc

# Flags de compilation
CFLAGS = -Wall -Wextra -Werror

# Fichiers sources
SRCS = server.c Printf/ft_printf.c Printf/ft_printf_utils.c Printf/ft_printf_hex.c

# Fichiers objets (correspondant aux fichiers sources)
OBJS = $(SRCS:.c=.o)

# Règle par défaut
all: $(NAME)

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
OBJS = ${SRCS:.c=.o}
# Comment créer la bibliothèque statique
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
#@echo "$(MAGENTA)	.----------------.  .----------------.  .-----------------. .----------------.   .----------------.  .----------------.  .----------------.  .----------------.  $(DEF_COLOR)"
#@echo "$(MAGENTA)	| .--------------. || .--------------. || .--------------. || .--------------. | | .--------------. || .--------------. || .--------------. || .--------------. |$(DEF_COLOR)"
#@echo "$(MAGENTA)	| | ____    ____ | || |     _____    | || | ____  _____  | || |     _____    | | | |  _________   | || |      __      | || |   _____      | || |  ___  ____   | |$(DEF_COLOR)"
#@echo "$(MAGENTA)	| ||_   \  /   _|| || |    |_   _|   | || ||_   \|_   _| | || |    |_   _|   | | | | |  _   _  |  | || |     /  \     | || |  |_   _|     | || | |_  ||_  _|  | |$(DEF_COLOR)"
#@echo "$(MAGENTA)	| |  |   \/   |  | || |      | |     | || |  |   \ | |   | || |      | |     | | | | |_/ | | \_|  | || |    / /\ \    | || |    | |       | || |   | |_/ /    | |$(DEF_COLOR)"
#@echo "$(MAGENTA)	| |  | |\  /| |  | || |      | |     | || |  | |\ \| |   | || |      | |     | | | |     | |      | || |   / ____ \   | || |    | |   _   | || |   |  __'.    | |$(DEF_COLOR)"
#@echo "$(MAGENTA)	| | _| |_\/_| |_ | || |     _| |_    | || | _| |_\   |_  | || |     _| |_    | | | |    _| |_     | || | _/ /    \ \_ | || |   _| |__/ |  | || |  _| |  \ \_  | |$(DEF_COLOR)"
#@echo "$(MAGENTA)	| ||_____||_____|| || |    |_____|   | || ||_____|\____| | || |    |_____|   | | | |   |_____|    | || ||____|  |____|| || |  |________|  | || | |____||____| | |$(DEF_COLOR)"
#@echo "$(MAGENTA)	| |              | || |              | || |              | || |              | | | |              | || |              | || |              | || |              | |$(DEF_COLOR)"
#@echo "$(MAGENTA)	| '--------------' || '--------------' || '--------------' || '--------------' | | '--------------' || '--------------' || '--------------' || '--------------' |$(DEF_COLOR)"
#@echo "$(MAGENTA)	'----------------'  '----------------'  '----------------'  '----------------'   '----------------'  '----------------'  '----------------'  '----------------'  $(DEF_COLOR)"


# Règle pour créer les fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers objets
clean:
	rm -f $(OBJS)

# Règle pour nettoyer tout (y compris la bibliothèque)
fclean: clean
	rm -f $(NAME)

# Règle pour recompiler tout
re: fclean all

# Marquer les cibles comme PHONY (ne correspondant pas à un fichier)
.PHONY: all clean fclean re
