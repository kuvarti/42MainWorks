# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/26 13:38:25 by aeryilma          #+#    #+#              #
#    Updated: 2022/08/11 10:47:42 by aeryilma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

CC		= gcc -g
CFLAGS	= -Wall -Wextra -Werror
INCLUDE	= -Iinclude -Isrc/ft_printf/Includes

PRINTF	= src/ft_printf/printf.a
SRC		= $(shell find src -name "*.c")
OBJ		= $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF)
	$(CC) $(CFLAGS) $(PRINTF) $(OBJ) $(INCLUDE) -o $(NAME)

$(PRINTF):
	make -C src/ft_printf

clean:
	@find src -name "*.o" -delete
	make -i -C src/ft_printf clean
	@echo "Objects Deleted"

fclean: clean
	@rm philo
	make -C src/ft_printf fclean
	@echo "Program Deleted"

re: fclean all

