NAME = Serializer

CC = c++ -std=c++98
CFLAGS = -Wall -Wextra -I./include # -Werror
ifeq ($(shell uname), Linux)
	CC = c++ -g
endif

SRC =  $(shell find . -name "*.cpp")
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@find . -name "*.o" -delete
	@echo "Cleaning"

fclean: clean
	@rm $(NAME)
	@echo "Done"

re: fclean all
