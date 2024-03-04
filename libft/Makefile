# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iverniho <iverniho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 17:38:23 by iverniho          #+#    #+#              #
#    Updated: 2023/12/11 18:40:17 by iverniho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strchr.c \
		ft_strlen.c ft_tolower.c ft_toupper.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_memchr.c ft_memcmp.c ft_strlcat.c ft_strncmp.c ft_strrchr.c ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_itoa.c


BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstiter.c \
		ft_lstclear.c ft_lstmap.c
NAME = libft.a
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUS_OBJ)
	ar rc $(NAME) $(OBJ) $(BONUS_OBJ)

clean:
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -Rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
