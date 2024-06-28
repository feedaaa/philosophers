NAME        = philo
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
SRC         = philo.c  utils.c doing_things.c init.c time.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(OBJ))
	$(CC) $(CFLAGS) -c

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re