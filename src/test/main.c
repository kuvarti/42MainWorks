#include "../ft_malloc.h"
#include <stdio.h>

int main() {
	char *str = (char *)malloc(10);
	printf("%%s : %s\n", str);
	printf("%%p : %p\n", str);
	printf("sizeof : %lu\n", sizeof(str));
	return 0;
}
