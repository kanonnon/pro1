#include <stdio.h>
#include <stdlib.h>

int main()
{
    int first, second;
    printf("input two integer: ");
    scanf("%d %d", &first, &second);
    printf("%10.4f\n", (float)first + second);
    printf("%10.4f\n", (float)first - second);
    printf("%10.4f\n", (float)first * second);
    printf("%10.4f\n", (float)first / second);
    return 0;
}