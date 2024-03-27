CC=gcc
CFLAGS=-g -I../include
LDFLAGS= -L../lib -lft_malloc

FTS= $(shell find . -name '*Ft.c')
FTPROGS= $(FTS:%Ft.c=%Ft)

STDS= $(shell find . -name '*Std.c')
STDPROGS= $(STDS:%Std.c=%Std)

all: $(FTPROGS) $(STDPROGS)

$(FTPROGS): %Ft: %Ft.c
	@$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(STDPROGS): %Std: %Std.c
	@$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -f $(FTPROGS) $(STDPROGS)
	@find . -name "*.dSYM" -delete
