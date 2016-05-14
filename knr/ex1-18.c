/* Write a program to remove trailing blanks and tabs from each line
 * of input, and to delete entirely blank lines */

#include <stdio.h>

#define MAXLN 1000

#define OUT 0
#define IN 1


int getln(char s[], int max);
int length(char s[]);
void strip(char s[]);


main()
{
    char line[MAXLN];

    while (getln(line, MAXLN) > 0) {
        strip(line);
        if (line[0] != '\0')
            printf("%s\n", line);
    }

    return 0;
}

/* Strip trailing blanks and tabs and newlines, in place. */
void
strip(char s[])
{
    int i;

    for (i = length(s) - 1; i >= 0; i--)
       /* The character tests can presumably be replaced with
        * isspace(), from the standard library. */
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
            break;

    /* This works on empty lines and all whitespace lines as the loop
     * terminates with i = -1. */
    s[i+1] = '\0';
}

/* Find the length of the string */
int
length(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
        ;
    return i;
}

int
getln(char s[], int lim)
{
    int c, i;

    i = 0;
    while (lim-- > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}
