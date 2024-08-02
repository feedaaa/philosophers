# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 13:28:08 by ffidha            #+#    #+#              #
#    Updated: 2024/08/02 10:20:10 by ffidha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		philo

SRCS		=		main.c				\
					parser.c			\
					printit.c			\
					init_struct.c		\
					init_philo.c		\
					forks.c				\
					clean.c				\
					life.c				\
					doing_things.c		\
					time.c				\
					record.c			\

UTILS		=		ft_put_fd.c			\
					ft_isdigit.c		\
					ft_atoi.c			\

SRCS_DIR	=		./srcs/

UTILS_DIR	=		./utils/

INCLUDES	=		./includes

CC			=		gcc

CFLAGS		=		-Wall -Werror -Wextra -pthread

OBJS		=		$(addprefix $(SRCS_DIR),$(SRCS:.c=.o))

UTILS_OBJS	=		$(addprefix $(UTILS_DIR),$(UTILS:.c=.o))

RM			=		rm -rf

$(NAME)		:		$(UTILS_OBJS) $(OBJS)
					$(CC) $(CFLAGS) $(UTILS_OBJS) $(OBJS) -I$(INCLUDES) -o $(NAME)
					clear
					@echo "Compilation  Successful!"

all			:		$(NAME)

clean		:
					@$(RM) $(OBJS) 
					@$(RM) $(UTILS_OBJS)

fclean		:		clean
					@$(RM) $(NAME)

re			:		fclean all

.PHONY		:	 all clean fclean re