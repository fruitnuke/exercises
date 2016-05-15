/* Exercise 4-4. Add commands to print the top element of the stack
 * without popping, to duplicate it, and to swap the top two elements.
 * Add a command to clear the stack. */

/* Notes: It may seem more natural to add keywords for the commands,
 * like "top", "dup" and "swap", that involves a bunch of extra
 * processing to parse those keywords. Much easier to add some more
 * single character operators, such as '@', '"' and '$', as the
 * framework is already set up for that and it's just a case of adding
 * in more cases to the switch.
 *
 * We already have a command for "print the top element of the stack",
 * though - '\n', so no need to create another one. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char s[]);
int getch(void);
void ungetch(char c);
void push(double f);
double pop(void);
double peek(void);
void clear(void);

int
main()
{
    int type;
    double op1;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: divide by zero\n");
            break;
        case '%':
            op2 = pop();
            push((int)pop() % (int)op2);
            break;
        case '\"':              /* duplicate the top element of the stack */
            push(peek());
            break;
        case '$':               /* swap the top two elements of the stack */
            op1 = pop();
            op2 = pop();
            push(op1);
            push(op2);
            break;
        case '#':               /* clear the stack */
            clear();
            break;
        case '\n':
            printf("\t%.8g\n", peek());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

int
getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
        return c;

    i = 0;

    if (c == '-'){
        c = getch();
        if (!isdigit(c) && c != '.') {
            ungetch(c);
            return '-';
        }
        s[++i] = c;
    }

    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;

    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int
getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void
ungetch(char c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void
push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double
pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

double
peek(void)
{
    if (sp > 0)
        return val[sp-1];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void clear(void)
{
    sp = 0;
}
