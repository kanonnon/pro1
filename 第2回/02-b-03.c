#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h1, m1, h2, m2, subtraction;
    printf("after time h1:m1\ninput h1 m1: ");
    scanf("%d %d", &h1, &m1);
    printf("before time h2:m2\ninput h2 m2: ");
    scanf("%d %d", &h2, &m2);

    subtraction = (h1 * 60 + m1) - (h2 * 60 + m2);
    printf("time subtraction (min) is %d\n", subtraction);
    printf("time subtraction is %d:%d\n", subtraction / 60, subtraction % 60);
}