# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/26 13:38:25 by aeryilma          #+#    #+#              #
#    Updated: 2022/08/12 17:19:43 by aeryilma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

CC		= gcc -g
CFLAGS	= -Wall -Wextra -Werror
INCLUDE	= -Iinclude -Isrc/ft_printf/Includes

SRC		= $(shell find src -name "*.c")
OBJ		= $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) -o $(NAME)


clean:
	@find src -name "*.o" -delete
	@echo "Objects Deleted"

fclean: clean
	@rm philo
	@echo "Program Deleted"

re: fclean all

