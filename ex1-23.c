/* Write a program to remove all comments from a C program.  Don't
 * forget to handle quoted strings and character constants properly.
 * C comments do not nest. */

/* Notes: "quoted strings" refers to string literals such as:
 *
 *     "this string \"/*not a comment *\/\" is not a comment"
 *
 * and character constants to '"', which should not be considered the
 * start of a string.
 *
 * This solution relies on the fact that once EOF is reached,
 * subsequent calls to getchar() will also continue to return EOF
 * (rather than result in an error).
 */

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char** argv)
{
    int in_comment = FALSE;
    int in_string = FALSE;

    int c = getchar();
    int d = getchar();

    for (; c != EOF; c = d, d = getchar()) {
        if (in_string == FALSE && c == '/' && d == '*') {
            in_comment = TRUE;
        }
        else if (in_comment == TRUE && c == '*' && d == '/') {
            in_comment = FALSE;
            /* Consume both 'c' and 'd' without printing them. */
            d = getchar();
            continue;
        }
        else if (in_string == FALSE && d == '"' && c != '\'' && c != '\\') {
            in_string = TRUE;
        }
        else if (in_string == TRUE && d == '"' && c != '\\') {
            in_string = FALSE;
        }

        if (in_comment == FALSE && c != EOF)
            printf("%c", c);
    }

    return 0;
}
