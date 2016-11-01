# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smrabet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/27 15:48:45 by smrabet           #+#    #+#              #
#    Updated: 2016/10/28 18:08:40 by smrabet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

HEAD = fractol.h

LIB = libft/

SRC = src/main.c \
	  src/fractales.c \
	  src/fractales_bonus.c \
	  src/fractales_bonus2.c \
	  src/key.c

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
	@echo "\033[1;33;40mclean Fractol"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIB)
	@echo "\033[1;31;40mfclean Fractol"

re: fclean all
