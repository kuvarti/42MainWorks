NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCLUDE = -Iinclude/

ifeq ($(shell uname), Linux)
MINILIBX = $(addprefix $(OUTPREFIX), libmlx_Linux.a)
MINILIBXFLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif

SRC = $(shell find src -name "*.c")
SRCDIR = $(sort $(dir $(SRC)))
SRCFLS = $(notdir $(SRC))

OUTPREFIX = builds/
OBJ = $(addprefix $(OUTPREFIX), $(SRCFLS:.c=.o))

vpath %.c $(SRCDIR)
$(OUTPREFIX)%.o: %.c
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

all: outfolder $(MINILIBX) $(NAME)

outfolder:
	@echo "Building Cub3d"
	@if [ ! -d $(OUTPREFIX) ]; then echo "$(OUTPREFIX) folder created."; fi
	@mkdir -p $(OUTPREFIX);
	@echo "Compiling Files..."

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(MINILIBX) $(MINILIBXFLAGS) -o $(NAME)

$(MINILIBX):
	@echo "Compiling Minilibx..."
	@make -C minilibx-linux 2> /dev/null > /dev/null
	@cp minilibx-linux/libmlx_Linux.a $(OUTPREFIX)/.
	@echo "Minilibx compiled."

clean:
	@echo "Cleaning..."
	@if [ -d $(OUTPREFIX) ]; then rm -rf $(OUTPREFIX); fi
	@make -C minilibx-linux clean 2> /dev/null > /dev/null

fclean: clean
	@echo "Full Cleaning..."
	@if [ ! -d $(NAME) ]; then rm -rf $(NAME); fi
	@echo "Full Cleaned."
