NAME = push_swap
PRINTF = src/printf/libftprintf.a

INCLUDE = src/printf/Includes
CFLAGS = -Wall -Wextra -Werror

SRC = $(shell find src -name '*.c' | grep -v "printf")
OBJ = $(SRC:.c=.o)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@ -I Include -I $(INCLUDE)

all: $(NAME)

$(NAME): $(PRINTF) $(OBJ)
	gcc $(CFLAGS) $(PRINTF) $(OBJ) -o $(NAME)

$(PRINTF):
	make -C src/printf

clean:
	rm -f $(OBJ)
	make clean -C src/printf

fclean: clean
	make fclean -C src/printf
	rm push_swap

re: fclean all
