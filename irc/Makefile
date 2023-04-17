NAME	= ircserv

#if on macosdo this
ifeq ($(shell uname), Darwin)
	CC		= c++ -g -std=c++98
else
	CC		= c++ -g
endif
CFLAGS	= # -Wall -Wextra -Werror
INCLUDE	= -Iinclude/

SRC		= $(shell find src -name "*.cpp")
SRCDIR	= $(sort $(dir $(SRC))) 
SRCFLS	= $(notdir $(SRC))

OUTPRE	= builds/
OBJ		= $(addprefix $(OUTPRE), $(SRCFLS:.cpp=.o))

vpath %.cpp $(SRCDIR)
$(OUTPRE)%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: prefix $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OUTPRE)

fclean: clean
	rm $(NAME)

re: fclean all

prefix:
	mkdir -p $(OUTPRE)