#
#!	MLX LINUX FOLDER NAME MUST BE minilibx-linux
#

NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = $(addprefix $(OUTPREFIX), libft.a)

INCLUDE = -Iinclude/

ifeq ($(shell uname), Linux)
MINILIBX = $(addprefix $(OUTPREFIX), libmlx_Linux.a)
MINILIBXFLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
EXTRAMINILIBXFLAGS =  -I/usr/include -Imlx_linux
else ifeq ($(shell uname), Darwin)
#
#TODO be filled
#
endif

SRC = $(shell find src -name "*.c" | grep -v "libft")
SRCDIR = $(sort $(dir $(SRC)))
SRCFLS = $(notdir $(SRC))

OUTPREFIX = builds/
OBJ = $(addprefix $(OUTPREFIX), $(SRCFLS:.c=.o))

vpath %.c $(SRCDIR)
$(OUTPREFIX)%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) $(EXTRAMINILIBXFLAGS) -c $< -o $@

all: outfolder $(LIBFT) $(MINILIBX) $(NAME) seperate
	@echo ""
	@echo "./$(NAME) is ready to use."

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

$(LIBFT):
	@echo "Compiling Libft..."
	@make -C src/libft 2> /dev/null > /dev/null
	@cp src/libft/libft.a $(OUTPREFIX)/.
	@echo "Libft compiled."

clean:
	@echo "Cleaning..."
	@if [ -d $(OUTPREFIX) ]; then rm -rf $(OUTPREFIX); fi
	@make -C src/libft fclean 2> /dev/null > /dev/null
	@make -C minilibx-linux clean 2> /dev/null > /dev/null

fclean: clean
	@echo "Full Cleaning..."
	@if [ ! -d $(NAME) ]; then rm -rf $(NAME); fi
	@echo "Full Cleaned."

seperate:
	@echo "---------------------"

re: fclean seperate all
