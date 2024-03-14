// #include "../src/ft_malloc.h"
#include <stdlib.h>
#include <stdio.h>

char *deneme1() {
	char *str = (char *)malloc(10);
	printf("%%s : %s\n", str);
	printf("%%p : %p\n", str);
	printf("sizeof : %lu\n", sizeof(str));
	return str;
}

int main() {
	char *ptr= deneme1();
	char *ptr2= deneme1();
	printf("getpagesize : %ld\n", ptr2 - ptr);
	return 0;
}
