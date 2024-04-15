# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 16:25:21 by iverniho          #+#    #+#              #
#    Updated: 2024/04/15 13:41:10 by iverniho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = so_long

CFLAGS = -Wall -Wextra -Werror
SRC = src/so_long.c src/utils.c src/img_tools.c src/parser.c src/validate_path.c \
	src/utils2.c

LIBFT = libft/
LIB = libft/libft.a
GNL := get_next_line/*c
PRINTF := printf/libftprintf.a
OBJ = $(SRC:.c=.o)

MLX_LIB = mlx/

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ)
	@if [ ! -d "mlx" ]; then \
	git clone https://github.com/42Paris/minilibx-linux.git mlx; \
	fi
	@make -C $(MLX_LIB)
	@make -C $(LIBFT)
	@make -C printf/
	$(CC) -g $(CFLAGS) $(OBJ) $(LIB) $(GNL) $(PRINTF) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf $(LIBFT)/*.o
	rm -rf printf/*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)/libft.a
	rm -f printf/libftprintf.a

re: fclean all

.PHONY: all clean fclean re

