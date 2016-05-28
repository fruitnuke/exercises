/* print longest input line */

#include <stdio.h>

#define MAXLINE 1000
#define MINLINE 80

int xgetline(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
    int len;  /* current line length */
    char line[MAXLINE];  /* current input line */

    while ((len = xgetline(line, MAXLINE)) > 0)
        if (len > MINLINE)
            printf("%s", line);

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
