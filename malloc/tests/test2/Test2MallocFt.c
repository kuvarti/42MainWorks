#include "ft_malloc.h"
#include "../libft/libft.h"
#include <string.h>
#include <stdio.h>

int main() {
	char **ptr = (char **)malloc(sizeof(char *) * 10);

	for (int i = 0; i < 10; i++) {
		ptr[i] = (char *)malloc(20);
		strcpy(ptr[i], "Hello World!");
	}

	ft_printf("ptr: %s, %p\n", ptr[1], ptr[1]);

	ptr[1][30] = 'c'; // This should crash
	ft_printf("changed: %c, %s\n", ptr[1][30], ptr[2]);
	show_alloc_mem();
	return 0;
}
