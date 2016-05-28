/* Write a program that copies its input to its output, replacing tabs
 * with '\t', backspaces by '\b' and backslashes by '\\' */

#include <stdio.h>

main() {
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\b')
            printf("\\b");
        else if (c == '\t')
            printf("\\t");
        else
            if (c == '\\')
            printf("\\\\");
        else
            putchar(c);
    }
}
