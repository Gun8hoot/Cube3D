#include <stdio.h>

int	main(void)
{
	int nb = 0x0;

	nb += 255 << 16;
	nb += 128 << 8;
	nb += 15;
	printf("%X\n", nb);
}
