NAME = so_long
BONUS = so_long-bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes/
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -L./minilibx
INCLUDES = -I./includes -I./minilibx

SRC = $(shell find src -name "*.c" ! -name "bonus*")
OBJS = $(SRC:.c=.o)

BSRC = 	$(shell find src/mapinput -name "*.c" ! -name "mapcheck*") $(shell find src/main -name "bonus*.c") src/main/main.c
BOBJS = $(BSRC:.c=.o)

MINILIBX = minilibx/libmlx.a

FTPRINTFD = src/ft_printf
FTPRINTF = $(FTPRINTFD)/libftprintf.a

all: $(MINILIBX) $(NAME)

.%c.%o:
	@$(CC) $(CFLAGS) $(INCLUDES)  -c $< -o $@

$(NAME): ftprintf $(OBJS)
	@echo "Program Linking Started"
	@$(CC) $(CFLAGS) $(OBJS) $(FTPRINTF) $(MLXFLAGS) $(MINILIBX) -o $(NAME)
	@echo "Program Linked"

bonus: $(BONUS)

$(BONUS): ftprintf $(BOBJS)
	@echo "Bonus Linking Started"
	@$(CC) $(CFLAGS) $(BOBJS) $(FTPRINTF) $(MLXFLAGS) $(MINILIBX) -o $(BONUS)
	@echo "Bonus Linked"

$(MINILIBX):
	MAKE -C minilibx 2>/dev/null
	cp minilibx/mlx.h includes/.

norm:
	@norminette $(shell find src/ -name "*.c")
	@norminette $(shell find includes/ -name "*.h" ! -name "mlx.h") -R checkForbidden

re: fclean all

ftprintf:
	make -C $(FTPRINTFD)

clean:
	find . -name "*.o" -delete -print
	rm includes/mlx.h
	make -C minilibx clean

fclean:clean
	rm $(NAME) $(BONUS)
	make -C $(FTPRINTFD) fclean

.PHONY: fclean clean all ftprintf re norm
