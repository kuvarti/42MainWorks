#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "ft_malloc.h"

int main() {
	void* handle;
	void* (*customMalloc)(size_t);
	char* error;

	// libft_malloc.so kütüphanesini yükle
	handle = dlopen("../lib/libft_malloc.so", RTLD_LAZY);
	if (!handle) {
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}

	// malloc fonksiyonunu dlsym ile al
	customMalloc = (void* (*)(size_t))dlsym(handle, "malloc");
	if ((error = dlerror()) != NULL)  {
		fprintf(stderr, "%s\n", error);
		exit(1);
	}

	void* ptr = customMalloc(1024); // kendi malloc'unuzu kullanarak bellek ayırma
	void* ptr2 = malloc(1024); // standart malloc kullanarak bellek ayırma
	show_alloc_mem();

	free(ptr);
	free(ptr2);
	dlclose(handle);

	return 0;
}
