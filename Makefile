CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I./ft_printf/Includes/.
PRINTF = ./ft_printf/libftprintf.a

SRNAME = server
CLNAME = client

all: $(SRNAME)

$(SRNAME): $(PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) server.c $(PRINTF) -o $(SRNAME)

clean:
	make -C ft_printf fclean
	rm server

re: clean all

$(PRINTF):
	make -C ft_printf
