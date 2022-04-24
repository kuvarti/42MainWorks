# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 02:30:16 by aeryilma          #+#    #+#              #
#    Updated: 2022/04/24 02:30:17 by aeryilma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I./ft_printf/Includes/.
PRINTF = ./ft_printf/libftprintf.a

SRNAME = server
CLNAME = client

all: $(CLNAME) $(SRNAME)

$(SRNAME): $(PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $(PRINTF) server.c -o $(SRNAME)

$(CLNAME): $(PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $(PRINTF) client.c -o $(CLNAME)

clean:
	rm server client

fclean: clean
	make -C ft_printf fclean

re: clean all

$(PRINTF):
	make -C ft_printf
