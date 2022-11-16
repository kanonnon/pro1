#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, num, total;
    total = 1;
    printf("input an integer: ");
    scanf("%d", &num);
    for (i = 1; i <= num; i++) {
        total *= i;
    }
    printf("%d! = %d\n", num, total);
    return 0;
}