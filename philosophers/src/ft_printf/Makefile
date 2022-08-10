
NAME		= printf.a
INCLUDE		= -IIncludes
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
AR			= ar rcs

SRC	= $(shell find . -name '*.c')
OBJ = $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(AR) $(NAME) $(OBJ)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@ -I Includes

clean:
			rm -f */*.o

fclean:		clean
			@$(RM) -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
