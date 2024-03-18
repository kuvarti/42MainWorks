#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	char **ptr = (char **)malloc(10);

	for (int i = 0; i < 10; i++) {
		ptr[i] = (char *)malloc(20);
	}

	strcpy(ptr[0], "Hello World!");
	strcpy(ptr[1], "Hello World!");
	strcpy(ptr[2], "Hello World!");
	strcpy(ptr[3], "Hello World!");
	strcpy(ptr[4], "Hello World!");
	strcpy(ptr[5], "Hello World!");
	strcpy(ptr[6], "Hello World!");
	strcpy(ptr[7], "Hello World!");
	strcpy(ptr[8], "Hello World!");
	strcpy(ptr[9], "Hello World!");

	ptr[1][25] = 'A';

	printf("ptr: %s, %p\n", ptr[1], ptr[1]);
	return 0;
}
