void *ft_memset(void *s, int c, size_t n)
{
	unsigned char *p = (unsigned char *)s;
	size_t	i;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
#include <stddef.h>
