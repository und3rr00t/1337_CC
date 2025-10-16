#include <stdio.h>

// Assume your ft_memset is declared here or in an included header
void *ft_memset(void *s, int c, size_t n);

int main(void)
{
    char buffer[10];

    // Initialize buffer with zeros
    ft_memset(buffer, 0, 10);

    // Fill bytes 3 to 6 with 'X' (ASCII 88)
    ft_memset(buffer + 3, 88, 4);

    // Print buffer as characters, showing non-printables as dots
    for (int i = 0; i < 10; i++)
    {
        if (buffer[i] >= 32 && buffer[i] <= 126)
            printf("%c ", buffer[i]);
        else
            printf(". ");
    }
    printf("\n");

    return 0;
}
#include <stddef.h>
