#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
	system("LD_PRELOAD=../lib/libft_malloc.so ./test1/Test1MallocFt");
}
