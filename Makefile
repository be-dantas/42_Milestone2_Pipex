# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/22 17:56:52 by bedantas          #+#    #+#              #
#    Updated: 2025/09/30 18:16:57 by bedantas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = 	pipex.c		\
		commands.c	\
		exec.c

OBJS = $(SRCS:.c=.o)

RMAKE = make re

all: $(NAME)

all: $(NAME)

$(NAME): $(OBJS)
	cd ./libft && $(RMAKE)
	cp ./libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)
	cc pipex.c $(NAME) -o pipex
	rm -f pipex.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	cd ./libft && make clean

fclean: clean
	rm -f $(NAME)
	cd ./libft && make fclean
	rm -f pipex

re: fclean all

.PHONY: all clean fclean re