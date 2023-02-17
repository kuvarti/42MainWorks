NAME = Polymorfism

CC = c++ -std=c++98
CFLAGS = -Wall -Wextra -Werror -I./include
ifeq ($(shell uname), Linux)
	CC = c++
endif

SRC =  $(shell find src -name "*.cpp")
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
