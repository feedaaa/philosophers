NAME = philo

SCR= main.c \
	utils.c	\
	extra.c	\
	time.c \
	simulation.c \

OBJ = $(SCR:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g3
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re