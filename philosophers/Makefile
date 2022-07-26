# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/26 13:38:25 by aeryilma          #+#    #+#              #
#    Updated: 2022/07/26 16:32:25 by aeryilma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INCLUDE	= -I include

SRC		= $(shell find src -name "*.c")
OBJ		= $(SRC:.c=.o)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@ $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(INCLUDE) -o $(NAME)

clean:
	@find src -name "*.o" -delete
	@echo "Objects Deleted"

fclean: clean
	@rm philo
	@echo "Program Deleted"

re: fclean all

yaz:
	@echo $(SRC)
