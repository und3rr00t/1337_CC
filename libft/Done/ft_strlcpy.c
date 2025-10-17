size_t	strlcpy(char *dst, const char *src, size_t size)
{
	size_t l = 0;
	while (src[l])
		l++;
	size_t i = 0;
	if (size == 0)
		return (l);
	while (i < size -1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (i <= l)
		dst[i] = '\0';
	return (l);
}
