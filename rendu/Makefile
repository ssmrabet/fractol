# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smrabet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/27 15:48:45 by smrabet           #+#    #+#              #
#    Updated: 2016/11/27 13:50:48 by smrabet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

HEAD = fractol.h

LIB = libft/

SRC = src/main.c \
	  src/fractales.c \
	  src/fractales_bonus.c \
	  src/fractales_bonus2.c \
	  src/key.c \
	  src/menu.c

GCC = gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework Appkit

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(GCC) -o $(NAME) $(OBJ) -L$(LIB) -lft
	@echo "\033[0;33;32mmake Fractol"

%.o: %.c $(HEAD)
	@$(GCC)  -c $<

clean:
	@make clean -C $(LIB)
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIB)

re: fclean all
