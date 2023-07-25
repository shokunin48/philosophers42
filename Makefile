# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibellash <ibellash@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 18:56:34 by ibellash          #+#    #+#              #
#    Updated: 2023/07/25 16:09:17 by ibellash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo 
SRCS =	main.c \
		threads.c \
		actions.c \
		init.c \
		atoi.c \
		utils.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS) 
	@$(CC) $(CFLAGS)  $(OBJS) -o $(NAME)
	@echo "Philosophers successfully compiled!"
 
all: $(NAME)

clean:
	@rm -rf $(OBJS)
	@echo "Philosophers successfully cleaned!"

fclean: clean
	@rm -rf $(NAME)
	
re: fclean all

.PHONY: all clean fclean re