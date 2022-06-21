# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 11:01:10 by aeryilma          #+#    #+#              #
#    Updated: 2022/06/21 15:31:05 by aeryilma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
FILES = $(shell find . -name '*.c')
OBJ = $(FILES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: ${NAME}

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	find . -name "*.o" -delete

fclean: clean
	rm libft.a

re: clean all

.PHONY:
	all ofile clean
