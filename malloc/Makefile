ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

INCLUDE= -I ./src
CC= gcc -g

TESTFLS= $(shell find test -name "*.c") $(shell find src -name "*.c")
TESTOBJ= $(TESTFLS:.c=.o)
LIBFT= libft/libft.a

%.o: %.c
	@$(CC) $(INCLUDE) -c $< -o $@

all: $(LIBFT) $(TESTOBJ)
	$(CC) $(INCLUDE) $(TESTOBJ) $(LIBFT) -o testt
	./testt

$(LIBFT):
	@make -C libft

clean:
	@rm -f $(TESTOBJ)
	@make -C libft clean

fclean: clean
	@make -C libft fclean

re: fclean all
