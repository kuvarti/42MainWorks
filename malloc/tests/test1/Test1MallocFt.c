#include "ft_malloc.h"
#include <string.h>
#include <stdio.h>

int main() {
	char **ptr = (char **)malloc(sizeof(char *) * 10);

	for (int i = 0; i < 10; i++) {
		ptr[i] = (char *)malloc(20);
		strcpy(ptr[i], "Hello World!");
	}

	// ptr[1][25] = 'A';

	printf("ptr: %s, %p\n", ptr[1], ptr[1]);

	show_alloc_mem();
	return 0;
}
