CC=gcc
CFLAGS=-g -I../include
LDFLAGS= -L../lib -lft_malloc

FTS= $(shell find . -name '*Ft.c')
FTPROGS= $(FTS:%Ft.c=%Ft)

STDS= $(shell find . -name '*Std.c')
STDPROGS= $(STDS:%Std.c=%Std)

all: $(FTPROGS) $(STDPROGS)

$(FTPROGS): %Ft: %Ft.c
	@pwd
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(STDPROGS): %Std: %Std.c
	@pwd
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(FTPROGS) $(STDPROGS)
	find . -name "*.dSYM" -delete

deneme:
	$(CC) $(CFLAGS) test1/Test1MallocFt.c $(LDFLAGS)
