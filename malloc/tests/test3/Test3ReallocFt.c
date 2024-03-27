#include "string.h"
#include "ft_malloc.h"
#include "libft.h"

int main() {
	char **ptr = (char **)malloc(sizeof(char *) * 10);

	for (int i = 0; i < 10; i++) {
		ptr[i] = (char *)malloc(20);
		ft_strlcpy(ptr[i], "Hello World!", 20);
		ft_printf("ptr[%d] set: %s, %p\n", i, ptr[i], ptr[i]);
	}

	ptr = (char **)realloc(ptr, sizeof(char *) * 20);
	for (int i = 10; i < 20; i++) {
		ptr[i] = (char *)malloc(20);
		ft_strlcpy(ptr[i], "Hello World!", 20);
		ft_printf("ptr[%d] set: %s, %p\n", i, ptr[i], ptr[i]);
	}
	ft_printf("ptr: %s, %p\n", ptr[1], ptr[1]);

	show_alloc_mem();
	return 0;
}
