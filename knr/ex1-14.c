#include <stdio.h>

#define CHAR_MIN ' '
#define CHAR_MAX '~'
#define ARRAY_SZ CHAR_MAX - CHAR_MIN + 1
#define WIDTH 77

main()
{
    int c;
    int counts[ARRAY_SZ];
    int freq, maxn;
    int i, j;
    float scale;

    for (i = 0; i < ARRAY_SZ; ++i)
        counts[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= CHAR_MIN && c <= CHAR_MAX)
            ++counts[c - CHAR_MIN];

    maxn = 0;
    for (i = 0; i < ARRAY_SZ; ++i)
        if (counts[i] > maxn)
            maxn = counts[i];

    scale = 1.0;
    if (maxn > WIDTH)
        scale = WIDTH / (float)maxn;

    for (i = 0; i < ARRAY_SZ; ++i) {
        printf("%c|", CHAR_MIN + i);

        freq = (int)(counts[i] * scale);
        for (j = 0; j < freq; ++j)
            printf("*");

        printf("\n");
    }
}
