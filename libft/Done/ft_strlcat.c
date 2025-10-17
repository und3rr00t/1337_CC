size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t ld;
	size_t ls;
	size_t i;

	i = 0;
	ld = 0;
	ls = 0;
	while (dst[ld] && ld < size)
		ld++;
	while (src[ls])
		ls++;
	if (size == 0)
		return (ls);
	if (ld >= size)
		return (ls + size);
	while (src[i] && (ld + i) < size - 1)
	{
		dst[ld + i] = src[i];
		i++;
	}
	if (ld + i < size)
		dst[ld + i] = '\0';
	return (ls + ld);
}
