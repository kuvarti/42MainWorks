#include "stdlib.h"
#include <stdio.h>

int main() {
	int *dizi = (int *)malloc(5 * sizeof(int));
	int *dizi2 = (int *)malloc(10 * sizeof(int));
	printf("dizi : %p\ndizi2 : %p\n", dizi, dizi2);


	for (int i = 0; i < 5; i++) {
		dizi[i] = i;
	}

	for (int i = 0; i < 10; i++) {
		dizi2[i] = i;
	}

	int a = 5;
	for (int i = 0; i < 100; i++) {
		dizi[i] = a;
		dizi2[i] = a;
		printf("%d, %d \n", dizi[i], dizi2[i]);
	}

	return 0;
}
