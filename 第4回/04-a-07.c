#include <stdio.h>

void swap(float *p, float *q)
{
    float t;
    t = *p;
    *p = *q;
    *q = t;
}

int main()
{
    float a, b;
    printf("Input 1st number: ");
    scanf("%f", &a);
    printf("Input 2nd number: ");
    scanf("%f", &b);
    swap(&a, &b);
    printf("Swapped 1st: %f, 2nd: %f\n", a, b);
    return 0;
}