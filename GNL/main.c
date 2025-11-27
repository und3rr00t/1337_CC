#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
    int     fd;
    char    *line;

    if (ac == 1)
    {
        printf("Reading from STDIN. Type text and press Ctrl+D:\n");
        fd = 0;
    }
    else
    {
        fd = open(av[1], O_RDONLY);
        if (fd < 0)
        {
            perror("Error opening file");
            return (1);
        }
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("LINE: %s", line);
        free(line);
    }

    if (ac > 1)
        close(fd);

    return (0);
}
