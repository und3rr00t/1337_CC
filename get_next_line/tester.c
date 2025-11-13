#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h" // Make sure this is in the same directory

// ------------------ Utilities ------------------

void test_line(char *line, int line_num)
{
    if (line)
        printf("Line %d: \"%s\"\n", line_num, line);
    else
        printf("Line %d: (null)\n", line_num);
    free(line);
}

// Compare GNL vs getline()
void compare_with_getline(const char *filename)
{
    printf("\n===== Comparing with getline(): %s =====\n", filename);
    int fd = open(filename, O_RDONLY);
    FILE *fp = fopen(filename, "r");
    if (fd == -1 || !fp)
    {
        perror("open");
        return;
    }

    char *gnl_line;
    char *std_line = NULL;
    size_t len = 0;
    int line_num = 1;
    int diff_found = 0;

    while (1)
    {
        gnl_line = get_next_line(fd);
        ssize_t read = getline(&std_line, &len, fp);

        if (!gnl_line && read == -1)
            break;

        if ((!gnl_line && read != -1) || (gnl_line && read == -1) ||
            strcmp(gnl_line, std_line) != 0)
        {
            diff_found = 1;
            printf("❌ Difference at line %d:\n", line_num);
            printf("   GNL: %s", gnl_line ? gnl_line : "(null)\n");
            printf("   STD: %s", std_line ? std_line : "(null)\n");
        }

        free(gnl_line);
        line_num++;
    }

    if (!diff_found)
        printf("✅ Perfect match with getline()!\n");

    free(std_line);
    close(fd);
    fclose(fp);
}

// Normal testing mode
void run_test(const char *filename)
{
    printf("\n===== Testing file: %s =====\n", filename);
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return;
    }

    char *line;
    int line_num = 1;
    while ((line = get_next_line(fd)))
        test_line(line, line_num++);

    close(fd);
    printf("===== End of %s =====\n\n", filename);
}

// ------------------ Main ------------------

int main(void)
{
    // Create test files dynamically
    system("echo -e 'Hello\\nWorld\\nThis is GNL\\n' > test1.txt");
    system("echo -n 'No newline at end' > test2.txt");
    system("echo -e '\\n\\n\\n' > test3.txt");
    system("echo -e 'Line1\\nLine2\\nLine3\\nLine4\\nLine5' > test4.txt");
    system("echo -n '' > empty.txt");
    system(\"printf '%01000d' 1 > longline.txt\"); // 1000-char long line

    // Standard tests
    run_test("test1.txt");
    run_test("test2.txt");
    run_test("test3.txt");
    run_test("test4.txt");
    run_test("empty.txt");
    run_test("longline.txt");

    // Multi FD test
    printf("\n===== Multi FD test =====\n");
    int fd1 = open("test1.txt", O_RDONLY);
    int fd2 = open("test4.txt", O_RDONLY);
    if (fd1 >= 0 && fd2 >= 0)
    {
        char *l1 = get_next_line(fd1);
        char *l2 = get_next_line(fd2);
        printf("FD1: %s", l1);
        printf("FD2: %s", l2);
        free(l1);
        free(l2);
        close(fd1);
        close(fd2);
    }
    else
        perror("open multi fd");

    // Bonus: compare your GNL with getline()
    compare_with_getline("test1.txt");
    compare_with_getline("test2.txt");
    compare_with_getline("test3.txt");
    compare_with_getline("longline.txt");
    compare_with_getline("empty.txt");

    // stdin test 
    // printf("\nType something (Ctrl+D to stop):\n");
    // char *input;
    // while ((input = get_next_line(STDIN_FILENO)))
    // {
    //     printf("You typed: %s", input);
    //     free(input);
    // }

    return 0;
}
