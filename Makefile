
INCLUDE= -I ./src

TESTFLS= $(shell find src -name "*.c")
TESTOBJ= $(TESTFLS:.c=.o)

.o: %.c
	@$(CC) $(INCLUDE) -c $< -o $@

# TODO	real project makefile:
# TODO	 -HOSTTYPE
# TODO	 -CC

print:
	@echo $(TESTFLS)
	@echo $(TESTOBJ)

test: $(TESTOBJ)
	$(CC) $(INCLUDE) $(TESTOBJ) -o test
