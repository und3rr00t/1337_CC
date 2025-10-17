#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int main()
{
	char d[15];
	printf("%zu\n", ft_strlcpy(d, "012345678901234567890123456789", 20));
	printf("%s", d);
}
