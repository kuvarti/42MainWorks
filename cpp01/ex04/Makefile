NAME = SedIsForLosers

CC = c++ -std=c++98
CFLAGS = -Wall -Werror -Wextra

SRC = $(shell find . -name "*.cpp")
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJ)	testfile
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

testfile:
	@echo "Volo pro veritas" > testfile

clean:
	@find . -name "*.o" -delete
	@find . -name "testfile.replace" -delete
	@echo "Cleaning"

fclean: clean
	@rm $(NAME)
	@rm testfile
	@echo "Done"

re: fclean all
