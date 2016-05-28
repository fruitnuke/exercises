/* Write a program `detab` that replaces tabs in the input with the
 * proper number of blanks to space to the next tab stop. Assume a
 * fixed set of tab stops, say every n column.  */

#include <stdio.h>


#define TABSTOP 4
#define MAXLINE 1000


int getln(char s[], int maxlen);
void detab(char in[], char out[], int maxlen);


main()
{
    char line1[MAXLINE];
    char line2[MAXLINE];

    while (getln(line1, MAXLINE) > 0) {
        detab(line1, line2, MAXLINE);
        printf("%s", line2);
    }
    return 0;
}


void
detab(char in[], char out[], int maxlen)
{
    int i, j;
    int next_stop;

    for (i = 0, j = 0; j < maxlen - 1 && in[i] != '\0'; ++i) {
        if (in[i] == '\t') {
            next_stop = ((j / TABSTOP) + 1) * TABSTOP;
            while (j < next_stop && j < maxlen - 1)
                out[j++] = ' ';
        }
        else {
            out[j++] = in[i];
        }
    }
    out[j] = '\0';
}


int
getln(char s[], int maxlen)
{
    int c, i;

    for (i = 0; i < maxlen - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}
