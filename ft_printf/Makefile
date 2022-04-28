
NAME		= libftprintf.a
INCLUDE		= include
LIBFT		= libft/libft
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
AR			= ar rcs

SRC	= $(shell find printf -name '*.c')
OBJ = $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C $(LIBFT)
			cp $(LIBFT)/libft.a .
			mv $(LIBFT)/libft.a $(NAME)
			$(AR) $(NAME) $(OBJ)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@ -I Includes

clean:
			rm -f */*.o
			rm libft.a
			make clean -C $(LIBFT)

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(LIBFT)/libft.a

re:			fclean all

.PHONY:		all clean fclean re
