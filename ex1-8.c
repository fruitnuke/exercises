/* Write a program to count blanks, tabs, and new lines */

#include <stdio.h>

main()
{
    int c;

    long nb = 0;
    long nt = 0;
    long nl = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++nb;
        if (c == '\t')
            ++nt;
        if (c == '\n')
            ++nl;
    }

    printf("blanks: %6ld\n", nb);
    printf("tabs:   %6ld\n", nt);
    printf("new lns:%6ld\n", nl);
}
