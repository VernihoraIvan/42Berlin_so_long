# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 16:25:21 by iverniho          #+#    #+#              #
#    Updated: 2024/04/04 12:26:40 by iverniho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = so_long.a

CFLAGS = -Wall -Wextra -Werror

SRC = so_long.c utils.c img_tools.c

LIB = libft/libft.a
GNL := get_next_line/*c 
OBJ = $(SRC:.c=.o)

MLX_LIB = mlx/

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -g $(CFLAGS) $(OBJ) $(LIB) $(GNL) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

