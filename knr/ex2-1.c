/* Exercise 2-1.  Write a program to determine the ranges of char,
 * short, int, and long variables, both signed and unsigned, by
 * printing appropriate values from standard headers and by direct
 * computation.  Harder if you compute them: determine the ranges of
 * the various floating-point types. */

#include <stdio.h>
#include <limits.h>

int main()
{
    printf("unsigned char:  %u - %u\n", (unsigned char)0x0U, (unsigned char)~0x0U);
    printf("unsigned short: %hu - %hu\n", (unsigned short)0x0U, (unsigned short)~0x0U);
    printf("unsigned int:   %u - %u\n",   (unsigned int)0x0U, (unsigned int)~0x0U);
    printf("unsigned long:  %lu - %lu\n", (unsigned long)0x0UL, (unsigned long)~0x0UL);
    printf("  signed char:  %d - %d\n", (signed char)SCHAR_MIN, (signed char)SCHAR_MAX);
    printf("  signed short: %hd - %hd\n", (signed short)SHRT_MIN, (signed short)SHRT_MAX);
    printf("  signed int:   %d - %d\n", (signed int)INT_MIN, (signed int)INT_MAX);
    printf("  signed long:  %ld - %ld\n", (signed long)LONG_MIN, (signed long)LONG_MAX);
}
