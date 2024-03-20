ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

INCLUDE= -I ./include -I ./libft
CC= gcc -g -fPIC -shared

MALLOCSRC = $(shell find src -name "*.c")
MALLOCDIR = $(sort $(dir $(MALLOCSRC)))
MALLOCFLS = $(notdir $(MALLOCSRC))

OUTPREFIX = builds/
MALLOCOBJ = $(addprefix $(OUTPREFIX), $(MALLOCFLS:.c=.o))

LIBFT = libft/libft.a

vpath %.c $(MALLOCDIR)
$(OUTPREFIX)%.o: %.c
	@$(CC) $(INCLUDE) -c $< -o $@

all: $(HOSTTYPE)
	@ln -sf libft_malloc_$(HOSTTYPE).so lib/libft_malloc.so

$(HOSTTYPE): $(LIBFT) outfolder $(MALLOCOBJ)
	@mkdir -p lib
	@$(CC) $(INCLUDE) $(MALLOCOBJ) $(LIBFT) -o lib/libft_malloc_$(HOSTTYPE).so
	@if [ ! -f "libft_malloc.so" ]; then \
		echo "libft_malloc_$(HOSTTYPE).so created."; \
		echo "Done."; \
	fi

$(LIBFT):
	@make -C libft

clean:
	@echo "Cleaning Malloc."
	@rm -rf $(OUTPREFIX)
	@make -C libft clean

fclean: clean
	@rm -rf lib
	@rm -f libft_malloc.so
	@make -C libft fclean
	@echo "Malloc Deleted."
	@echo "-----------------"

re: fclean all

outfolder: seperate
	@if [ ! -d "${OUTPREFIX}" ]; then \
		echo "Building Malloc"; \
		mkdir -p "${OUTPREFIX}"; \
		echo "${OUTPREFIX} folder created."; \
		echo "Compiling Files..."; \
	fi

seperate:
	@echo "-----------------"
