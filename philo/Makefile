NAME = philo
CC = @cc
RM = rm -f
CFLAGS = -Werror -Wextra -Wall
SRC = philo.c utils.c utils1.c error.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	@make -C costumizing/
# @echo "\033[0;32m\n🛠   Compiling philo...   🛠"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
# -fsanitize=address
	@echo "✅ 	Done!	  ✅\n"

clean:
	@echo "\033[0;31m\n❌  Deleting objects...   ❌"
	@$(RM) $(OBJ)
	@echo "\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;31m❌  Deleting executable... ❌"
	@$(RM) $(NAME)
	@$(RM) $(B_NAME)
	@echo "\n✔️✔️✔️  Deleted successfuly   ✔️✔️✔️ \n\033[0m"

re: fclean all
