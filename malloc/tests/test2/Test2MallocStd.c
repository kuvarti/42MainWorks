#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	char **ptr = (char **)malloc(sizeof(char *) * 10);

	for (int i = 0; i < 10; i++) {
		ptr[i] = (char *)malloc(20);
		strcpy(ptr[i], "Hello World!");
	}

	printf("ptr: %s, %p\n", ptr[1], ptr[1]);
	ptr[1][30] = 'c'; // This should crash
	printf("changed: %c, %s\n", ptr[1][30], ptr[2]);
	return 0;
}
