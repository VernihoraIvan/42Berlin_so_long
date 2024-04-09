# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 12:56:25 by iverniho          #+#    #+#              #
#    Updated: 2023/12/22 15:50:00 by iverniho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_strchr.c ft_putstr.c ft_putpointer.c ft_putnumber.c ft_puthex.c \
		ft_putunnumber.c ft_putchar.c
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
