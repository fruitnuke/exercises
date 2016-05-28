/* print longest input line */

#include <stdio.h>

#define MAXLINE 1000

int xgetline(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
    int len;  /* current line length */
    int max;  /* max line length seen so far */
    char line[MAXLINE];  /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = xgetline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }

    if (max > 0)
        printf("%d:%s", max, longest);

    return 0;
}

/* xgetline:  read a line into s, return length */
int xgetline(char s[], int maxline)
{
    int c, i;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    if (c != '\n') {
        while ((c = getchar()) != EOF && c != '\n')
            ++i;
        if (c == '\n')
            ++i;
    }

    return i;
}

/* copy:  copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
