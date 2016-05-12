/* Write a program to print a histogram of the lengths of words in its
 * input. */

#include <stdio.h>

#define OUT 0
#define IN 1

#define MAX_WORD_LEN 20
#define SZ MAX_WORD_LEN - 1  /* don't count words of length 0 */

main()
{
    int c, i, j, nc;
    int lengths[SZ];

    nc = 0;
    for (i = 0; i < SZ; ++i)
        lengths[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t' && c != '\n')
            ++nc;
        else if (nc > 0) {
            if (nc <= MAX_WORD_LEN)
                ++lengths[nc];
            nc = 0;
        }
    }

    for (i = 0; i < SZ; ++i) {
        printf("%3d|", i + 1);
        for (j = 0; j < lengths[i]; ++j)
            printf("*");
        printf("\n");
    }
}

