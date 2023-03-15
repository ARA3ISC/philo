NAME = philo
CC = @cc
RM = rm -f
CFLAGS = -Werror -Wextra -Wall
# -fsanitize=thread -g3
SRC = philo.c utils.c utils1.c utils2.c error.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	@make -C costumizing/
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@make -C costumizing mse7
	@$(RM) $(OBJ)
	@echo "\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME)
	@$(RM) $(B_NAME)

re: fclean all
