#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
	if (argc <= 1) {
		printf("Usage: %s <test Executables>\n", argv[0]);
		return 1;
	}

	system("LD_PRELOAD=../lib/libft_malloc.so ./test1/Test1MallocFt");
}
