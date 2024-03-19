ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

INCLUDE= -I ./include -I ./libft
CC= gcc -g

TESTFLS= tests/test1/Test1FtMalloc.c $(shell find src -name "*.c")
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
