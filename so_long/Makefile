#When you see same lines its for;
#Up comments for linux
#down comments for mac

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes/

#MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -L./minilibx
MLXFLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

INCLUDES = -I./includes -I./minilibx

SRC = $(shell find src -name "*.c")
OBJS = $(SRC:.c=.o)

#MINILIBX = minilibx/libmlx.a
MINILIBX = minilibx/libmlx_Linux.a

FTPRINTFD = src/ft_printf
FTPRINTF = $(FTPRINTFD)/libftprintf.a

all: $(MINILIBX) $(NAME)

.%c.%o:
	#@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@$(CC) $(CFLAGS) $(INCLUDES) -c -Imlx_linux -O3 -I/usr/include $< -o $@

$(NAME): ftprintf $(OBJS)
	@echo "Program Linking Started"
	@$(CC) $(CFLAGS) $(OBJS) $(FTPRINTF) $(MLXFLAGS) $(MINILIBX) -o $(NAME)
	@echo "Program Linked"

$(MINILIBX):
	make -C minilibx 2>/dev/null
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
	rm $(NAME)
	make -C $(FTPRINTFD) fclean

.PHONY: fclean clean all ftprintf re norm
