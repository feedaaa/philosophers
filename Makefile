NAME		= philo
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC			= philo.c /
				parse.c utils.c /
				doing_things.c /
				init.c

OBJ = $(SRC:.c=.o)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re