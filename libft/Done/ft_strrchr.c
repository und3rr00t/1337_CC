char *ft_strrchr(const char *s, int c)
{
	char	*ss;
	int l;
	
	ss = (char *)s;
	l  = 0;
	while (ss[l])
		l++;
	while (l >= 0)
	{
		if (ss[l] == c)
			return (&ss[l]);
		l--;
	}
	return (NULL);
}
