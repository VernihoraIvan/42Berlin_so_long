# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 16:25:21 by iverniho          #+#    #+#              #
#    Updated: 2024/03/04 16:41:12 by iverniho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = so_long.a
CFLAGS = -Wall -Wextra -Werror

SRC= so_long.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -Rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

