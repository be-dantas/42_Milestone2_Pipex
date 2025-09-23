# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/22 17:56:52 by bedantas          #+#    #+#              #
#    Updated: 2025/09/23 13:14:37 by bedantas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = 	pipex.c	\
		utils.c	\

OBJS = $(SRCS:.c=.o)

RMAKE = make re

all: $(NAME)

all: $(NAME)

$(NAME): $(OBJS)
	cd ./libft && $(RMAKE)
	cp ./libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	cd ./libft && make clean

fclean: clean
	rm -f $(NAME)
	cd ./libft && make fclean

re: fclean all

.PHONY: all clean fclean re