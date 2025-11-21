#include "get_next_line_bonus.h"

static char	*extract(char *s)
{
	int		i = 0;
	int		len;
	char	*p;

	if (!s || !s[0])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	len = i + (s[i] == '\n');
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		p[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		p[i++] = '\n';
	p[i] = 0;
	return (p);
}

static char	*clean(char *s)
{
	int		i = 0;
	int		j = 0;
	char	*p;

	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
		return (free(s), NULL);
	i++;
	p = malloc(ft_strlen(s) - i + 1);
	if (!p)
		return (NULL);
	while (s[i])
		p[j++] = s[i++];
	p[j] = 0;
	free(s);
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*s[1024];
	char		b[BUFFER_SIZE + 1];
	int			x;
	char		*line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	x = 1;
	while (!ft_strchr(s[fd], '\n') && x > 0)
	{
		x = read(fd, b, BUFFER_SIZE);
		if (x < 0)
			return (free(s[fd]), s[fd] = NULL, NULL);
		b[x] = 0;
		s[fd] = ft_strjoin(s[fd], b);
	}
	line = extract(s[fd]);
	s[fd] = clean(s[fd]);
	return (line);
}
