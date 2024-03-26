#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main() {
	char **ptr = (char **)malloc(sizeof(char *) * 10);

	for (int i = 0; i < 10; i++) {
		ptr[i] = (char *)malloc(20);
		strcpy(ptr[i], "Hello World!");
		printf("ptr[%d] set: %s, %p\n", i, ptr[i], ptr[i]);
	}

	ptr = (char **)realloc(ptr, sizeof(char *) * 20);
	for (int i = 10; i < 20; i++) {
		ptr[i] = (char *)malloc(20);
		strcpy(ptr[i], "Hello World!");
		printf("ptr[%d] set: %s, %p\n", i, ptr[i], ptr[i]);
	}
	printf("ptr: %s, %p\n", ptr[1], ptr[1]);
	return 0;
}
