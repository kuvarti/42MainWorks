# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 15:44:31 by aeryilma          #+#    #+#              #
#    Updated: 2022/06/27 17:44:09 by aeryilma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	rnd.rb is only for generate random numbers
#	usage : ruby rnd.rb [number]
#	with push_swap usage : TMS=[number]; ARG=$(ruby rnd.rb $TMS); ./push_swap $ARG ...
#	make; TMS=500; ARG=$(ruby rnd.rb $TMS); ./push_swap $ARG | ./checker $ARG; ./push_swap $ARG | wc -l

NAME = push_swap
PRINTF = src/printf/libftprintf.a

INCLUDE = src/printf/Includes
CFLAGS = -Wall -Wextra -Werror

SRC = $(shell find src -name '*.c' | grep -v "printf") #$(shell find src/sorting -name '*.c')
OBJ = $(SRC:.c=.o)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@ -I include -I $(INCLUDE)

all: $(NAME)

$(NAME): $(PRINTF) $(OBJ)
	gcc $(CFLAGS) $(PRINTF) $(OBJ) -I include -I $(INCLUDE) -o $(NAME)

$(PRINTF):
	make -C src/printf

clean:
	rm -f $(OBJ)
	make clean -C src/printf

fclean: clean
	make fclean -C src/printf
	rm push_swap

norm:
	@norminette $(SRC)
	norminette */*.h

re: fclean all
