#include <stdio.h>

#define IN  1   /* In whitespace. */
#define OUT 0

main()
{
    int c, state;

    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t' && c != '\n') {
            putchar(c);
            state = OUT;
        }
        else if (state == OUT) {
            putchar('\n');
            state == IN;
        }
    }
}
