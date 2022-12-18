#include <stdio.h>

int main()
{
    int n, i = 1, total = 0;
    printf("input a positive integer : ");
    scanf("%d", &n);
    while (i <= n) {
        total += i;
        i++;
    }
    printf("total : %d\n", total);
    return 0;
}