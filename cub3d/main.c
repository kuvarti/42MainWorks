#include "mlx.h"

int main()
{
	void *deneme = mlx_init();
	if (!deneme)
		deneme = 0;
}
