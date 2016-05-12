#include <stdio.h>

int main()
{
    int lower = 0;
    int upper = 300;
    int step = 20;

    float cels = lower;
    float fahr = 0;

    puts("  C   F");
    puts("--- ---");

    while (cels <= upper) {
        fahr = ((cels * 9.0) / 5.0) + 32.0;
        printf("%3.0f %3.0f\n", cels, fahr);
        cels += step;
    }
}
