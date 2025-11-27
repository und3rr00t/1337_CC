#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	s1_len;
	size_t	s2_len;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = 0;
	}
	joined = malloc(ft_strlen(s1) + ft_strlen(s2)+ 1);
	if (!joined)
		return (free(s1), NULL);
	i = 0;
	while (s1[i])
		joined[i] = s1[i++];
	j = 0;
	while (s2[j])
		joined[i++] = s2[j++];
	joined[i] = 0;
	return (free(s1), joined);
}
