NAME = TheJobOfYour

CC = c++ -std=c++98
CFLAGS = -Wall -Wextra -Werror

FILES = tests.cpp Account.cpp
OBJ = $(FILES:.cpp=.o)

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
