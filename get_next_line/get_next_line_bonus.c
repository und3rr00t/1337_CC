#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFFER_SIZE 42
#define FD_MAX 1024
size_t ft_strlen(const char *s)
{
    size_t  i;
    i = 0;

    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}
char *ft_strchr(const char *s, int c)
{
    if (!s)
        return (NULL);
    int i;
    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return ((char *)&s[i]);
        i++;
    }
    return (NULL);
}
char *ft_strjoin(char *s1, char *s2)
{
    if (!s1)
    {
        s1 = malloc(1);
        s1[0] = 0;
    }
    char *joined;
    size_t s1_len = ft_strlen(s1);
    size_t s2_len = ft_strlen(s2);
    joined = malloc(s1_len + s2_len + 1);
    if (!joined)
    {
        free(s1);
        return (NULL);
    }
    int i = 0;
    while (s1[i])
    {
        joined[i] = s1[i];
        i++;
    }
    int j = 0;
    while (s2[j])
        joined[i++] = s2[j++];
    joined[i] = 0;
    free(s1);
    return (joined);
}
char    *read_file(int fd, char *stash)
{
    char *buffer;
    int readed_bytes;
    
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    readed_bytes = 1;
    while (!ft_strchr(stash, '\n') && readed_bytes != 0)
    {
        readed_bytes = read(fd, buffer, BUFFER_SIZE);
        if (readed_bytes == -1)
        {
            free(buffer);
            free(stash);
            return (NULL);
        }
        buffer[readed_bytes] = 0;
        stash = ft_strjoin(stash, buffer);
    }
    free(buffer);
    return (stash);
}
char *ft_line(char *stash)
{
    char *line;
    if (!stash || !stash)
        return (NULL);
    int i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        line = malloc(i + 2);
    else
        line  = malloc(i + 1);
    if (!line)
        return (NULL);
    i = 0;
    while (stash[i] && stash[i] != '\n')
    {
        line[i] = stash[i];
        i++;
    }
    if (stash[i] == '\n')
        line[i++] = '\n';
    line[i] = 0;
    return (line);
}
char *ft_new_stash(char *stash)
{
    char *new_stash;
    int i = 0;
    int j = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i])
    {
        free(stash);
        return (NULL);
    }
    i++;
    new_stash = malloc(ft_strlen(stash) - i + 1);
    if (!new_stash)
        return(free(stash), NULL);
    while (stash[i])
        new_stash[j++] = stash[i++];
    new_stash[j] = 0;
    free(stash);
    return(new_stash);
}
char *get_next_line_bonus(int fd)
{
    static char *stash[FD_MAX];
    char    *line;

    if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
        return (NULL);
    stash[fd] = read_file(fd, stash[fd]);
    if (!stash[fd])
        return (NULL);
    line = ft_line(stash[fd]);
    stash[fd] = ft_new_stash(stash[fd]);
    return (line);
}
