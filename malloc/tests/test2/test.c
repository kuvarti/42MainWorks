#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "signal.h"
#include <unistd.h>

void _free(void **ptr) {
	for (int i = 0; i < 10; i++) {
		free(ptr[i]);
	}
	free(ptr);
}

void **_alloc() {
	void **ptr = (void **)calloc(10, sizeof(void *));

	for (int i = 0; i < 10; i++) {
		ptr[i] = (void *)calloc(20, sizeof(void));
	}
	return ptr;
}

void _assign(void **ptr) {
	for (int i = 0; i < 10; i++) {
		strcpy(ptr[i], "Hello World!");
	}
}

int main() {
	char **ptr = (char **)_alloc();
	_assign((void **)ptr);
	printf("ptr: %s, %p\n", ptr[1], ptr[1]);

	// _free((void **)ptr);
	printf("ptr: %s, %p\n", ptr[1], ptr[1]);
	printf("ptr: %s, %p\n", ptr[5], ptr[5]);
	free(&ptr[5][3]);
}
