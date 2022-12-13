NAME = PhoneBook

CC = c++ -std=c++98
CFLAGS = -Wall -Wextra -Werror

FILES = $(shell find . -name "*.cpp")
OBJ = $(FILES:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm $(OBJ)

fclean: clean
	@rm $(NAME)
	@echo "Done"
