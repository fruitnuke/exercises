/* Write a program to remove trailing blanks and tabs from each line
 * of input, and to delete entirely blank linkes */

#include <stdio.h>

#define MAXLN 1000

#define OUT 0
#define IN 1

main()
{
    int c;
    int state;
    int start;
    int i;
    char line[MAXLN];

    while (1)
    {
        for (i = 0, start = 0; i < MAXLN - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
            line[i] = c;

            if (c == ' ' || c == '\t') {
                if (state == OUT) {
                    state = IN;
                    start = i;
                }
            }
            else
                state = OUT;
        }

        if (state == IN)
            i = start;

        if (c == '\n' && i > 0) {
            line[i] = c;
            ++i;
        }

        line[i] = '\0';

        printf("%s", line);

        if (c == EOF)
            break;
    }

    return 0;
}
