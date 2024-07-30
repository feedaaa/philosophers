NAME				= philo
CC					= gcc
FLAGS				= -Wall -Wextra -Werror 

SRCS        		=     src/doing_things.c \
                          src/free_all.c \
                          src/init.c \
                          src/init_threads.c \
                          src/life.c \
                          src/parse.c \
                          src/philo.c \
                          src/record.c \
                          src/time.c \
						  src/forks.c \
                          utils/ft_atoi.c \
                          utils/ft_putnbr_fd.c \
                          utils/print_it.c \
                          
OBJS				= $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

RED		    		= \033[1;31m
GREEN				= \033[1;32m

RM		    		= rm -f

${NAME}:	${OBJS}
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN) Successfull Compilation"

all:		${NAME}

clean:
			@ ${RM} $(OBJS)
			@ echo "$(RED)Deleting objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re