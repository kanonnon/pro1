#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    float f_a;

    printf("input a: ");
    scanf("%d", &a);
    printf("input b: ");
    scanf("%d", &b);
    f_a = a;

    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d x %d = %d\n", a, b, a * b);
    printf("%d / %d = %f\n", a, b, f_a / b);
    return 0;
}