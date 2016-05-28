/* Write a program to copy its input to its output, replacing one or
 * more blanks with a single blank */

#include <stdio.h>

main()
{
    int c;
    int prev;

    while ((c = getchar()) != EOF)
    {
        if (c != ' ') {
            prev = c;
            putchar(c);
        }

        if (c == ' ')
        {
            if (prev != ' ') {
                prev = c;
                putchar(c);
            }
        }
    }
}
