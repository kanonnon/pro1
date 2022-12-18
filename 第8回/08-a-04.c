#include <stdio.h>

int main()
{
    int i = 0, n, total = 0;
    while (i < 5) {
        printf("input a positive integer : ");
        scanf("%d", &n);
        if (n < 0) {
            printf("Error : invalid input\n");
            continue;
        } else if (n == 0) {
            break;
        }
        total += n;
        i++;
    }
    printf("total : %d\n", total);
    return 0;
}