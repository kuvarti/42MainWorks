CC=gcc
CFLAGS=-g -I../include
LDFLAGS=-L../lib -lft_malloc
EXECUTABLE=testMain

FTS= $(shell find . -name '*Ft.c')
FTPROGS= $(FTS:%Ft.c=%Ft)

STDS= $(shell find . -name '*Std.c')
STDPROGS= $(STDS:%Std.c=%Std)

$(FTPROGS): %Ft: %Ft.c
	@pwd
	gcc $(CFLAGS) $< -o $@ $(LDFLAGS)

$(STDPROGS): %Std: %Std.c
	@pwd
	gcc $(CFLAGS) $< -o $@

all: $(EXECUTABLE)

$(EXECUTABLE): testMain.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -f $(FTPROGS) $(STDPROGS)

dd: $(FTPROGS) $(STDPROGS)

deneme:
	$(CC) $(CFLAGS) test1/Test1MallocFt.c $(LDFLAGS)
