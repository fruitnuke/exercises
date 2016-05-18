/* Write a program `entab` that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing.  Use
 * the same tab stops as for `detab`.  When either a tab or a single
 * blank would suffice to reach a tab stop, which should be given
 * preference? */

/* Answer: Give the space preference when a single blank suffices to
 * reach the tab stop, so that spaces in sentences are unaffected and
 * prose flows naturally. */

#include <stdio.h>

#define TABSTOP 4
#define MAXLEN 1000
#define IN 1
#define OUT 0

int getln(char s[], int maxlen);
void entab(char s[]);

int
main(int argc, char** argv)
{
    char line[MAXLEN];

    while (getln(line, MAXLEN) > 0) {
        entab(line);
        printf("%s", line);
    }
    return 0;
}

void
entab(char s[])
{
    int i; /* Index of character we're at in original string */
    int j; /* Index of character we're writing at in the new string (in place) */
    int k; /* Count of how many spaces in a row we've seen */

    i = j = 0;
    while (s[i] != '\0') {
        if (s[i] == ' ') {
            /* Copy the spaces directly, but keep track of how many in
             * a row we've seen. When we reach a tab stop write a tab
             * character at the start of the last k spaces with a tab
             * character, and reset the count. The value of k will
             * never be greater than TABSTOP. */
            k = 0;
            while (s[i] == ' ') {
                s[j++] = s[i++];
                ++k;
                if (k > 1 && (i % TABSTOP) == 0) {
                    j -= k;
                    k = 0;
                    s[j++] = '\t';
                }
            }
        }
        else
            s[j++] = s[i++];
    }

    s[j] = '\0';
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
