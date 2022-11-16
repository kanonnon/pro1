#include <stdio.h>

void aster(int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("*");
    }
    printf("\n");
}

int main()
{
    int n;
    printf("input a positive integer: ");
    scanf("%d", &n);
    aster(n);
    return 0;
}