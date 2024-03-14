#include "../ft_malloc.h"
#include <stdlib.h>
#include <stdio.h>

void deneme1() {
	char *str = (char *)malloc(10);
	printf("%%s : %s\n", str);
	printf("%%p : %p\n", str);
	printf("sizeof : %lu\n", sizeof(str));
}

int main() {
	deneme1();
	return 0;
}
