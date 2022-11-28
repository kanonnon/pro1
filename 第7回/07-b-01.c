#include <stdio.h>
#include <stdlib.h>

float my_pow(int a, int b)
{
    if (b == 0) {
        return 1;
    }
    return (float)a * my_pow(a, b - 1);
}

int main()
{
    int a, b;
    printf("Input two integers : ");
    scanf("%d %d", &a, &b);
    if (b > 0) {
        printf("a^b = %f\n", my_pow(a, b));
    } else if (b < 0) {
        printf("a^b = %f\n", 1 / my_pow(a, abs(b)));
    }
    return 0;
}