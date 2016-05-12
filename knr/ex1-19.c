/* Write a function reverse(s) that reverses the character string
 * s. Use it to write a program that reverses its input a line at a
 * time. */

#include <stdio.h>

#define MAXLEN 1000

int getln(char line[], int maxlen);
void reverse(char s[]);

main()
{
    char line[MAXLEN];

    while (getln(line, MAXLEN) > 0) {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}

void reverse(char s[])
{
    int i, j;
    char tmp;

    i = 0;
    j = 0;
    while (s[j] != '\0' && s[j] != '\n')
        ++j;

    /* if not the empty string, point j to the character before \0 or \n */
    if (j > 0)
       --j;

    while (i < j) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        ++i;
        --j;
    }
}

int getln(char line[], int maxlen)
{
    int c, i;

    for (i = 0; i < maxlen - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n')
        line[i++] = c;

    line[i] = '\0';
    return i;
}
