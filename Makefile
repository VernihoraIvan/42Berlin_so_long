# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 16:25:21 by iverniho          #+#    #+#              #
#    Updated: 2024/03/05 19:17:17 by iverniho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = so_long.a

CFLAGS = -Wall -Wextra -Werror

SRC = so_long.c

LIB = libft/libft.a

OBJ = $(SRC:.c=.o)

MLX_LIB = mlx/

# MLX_API = -lmlx -framework OpenGL -framework AppKit
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

all: $(NAME)

# $(NAME): $(OBJ)
# 	ar rc $(NAME) $(OBJ) -c $< -o $@

# gcc main.c ... libmlx42.a -Iinclude -ldl -lglfw -pthread -lm

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

