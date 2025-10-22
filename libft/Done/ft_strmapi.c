char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	unsigned int	l;
	unsigned int	i;

	i = 0;
	l = ft_strlen(s);
	if (!s || !f)
		return (NULL);
	ret =(char *)malloc(sizeof(char) * (l + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
