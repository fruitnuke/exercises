/* Write a function reverse(s) that reverses the character string
 * s. Use it to write a program that reverses its input a line at a
 * time. */

#include <stdio.h>

#define MAXLEN 1000

int getstr(char s[], int maxlen);
void reverse(char s[]);

main()
{
    char line[MAXLEN];

    while (getstr(line, MAXLEN) > 0) {
        reverse(line);
        printf("%s\n", line);
    }

    return 0;
}

int length(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; ++i)
        ;
    return i;
}

void reverse(char s[])
{
    int i, j, tmp;

    for (i = 0, j = length(s) - 1; i < j; ++i, --j) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

/* getstr: return a line of input without trailing '\n' */
int getstr(char s[], int maxlen)
{
    int c, i;

    for (i = 0; i < maxlen && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    s[i] = '\0';
    return i;
}
