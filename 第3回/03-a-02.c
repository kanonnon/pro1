#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, num;
    printf("input an integer: ");
    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        printf("*");
    }
    printf("\n");
    return 0;
}