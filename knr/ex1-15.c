/* Rewrite the temperature conversion program of Section 1.2 to use a
 * function for conversion. */

#include <stdio.h>

int convert(int fahrenheit);

main()
{
    int f, c;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    f = lower;
    while (f <= upper) {
        printf("%d\t%d\n", f, convert(f));
        f += step;
    }

    return 0;
}

int convert(int fahrenheit)
{
    return (5 * (fahrenheit - 32)) / 9;
}
