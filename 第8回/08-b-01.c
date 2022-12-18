#include <stdio.h>

int main()
{
    int n, i = 1;
    printf("Input number : ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Incorrect Input\n");
    } else {
        printf("%d is divisible by ", n);
        do {
            if (n % i == 0) {
                printf("%d ",i);
            }
            i++;
        } while (i <= n);
        printf("\n");
    }
    return 0;
}