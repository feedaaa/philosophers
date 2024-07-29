NAME        = philo

CC          = cc

CFLAGS      = -Wall -Wextra -Werror
SRC         = 	philo.c \
				doing_things.c \
				init.c \
				time.c \

UTILS		= 	ft_putstr_fd.c \
				ft_atoi.c \
				ft_putnbr_fd.c \

UTILS_DIR	=	./utils/

OBJ =				$(SRC:.c=.o)

UTILS_OBJS	=		$(addprefix $(UTILS_DIR),$(UTILS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(UTILS_OBJS)
	$(CC) $(CFLAGS) $(UTILS_OBJS) $(OBJ) -o $(NAME)
	clear
	@echo "Successful Compilation"

clean:
	@rm -rf $(OBJ)
	@rm -rf $(UTILS_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re