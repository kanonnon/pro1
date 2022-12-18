#include <stdio.h>

int main()
{
    int n, i = 2, j, check, count;
    scanf("%d", &n);
    printf("%d is multiplication of ", n);
    if (n == 1) {
        printf("1");
    }
    while (n > 1) {
        check = 0;
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                check = 1;
            }
        }
        if (check == 1) {
            i++;
            continue;
        }
        count = 0;
        while (1) {
            if (n % i == 0) {
                n /= i;
                count++;
            } else {
                if (count != 0) {
                    printf("%d^%d ", i, count);
                }
                break;
            }
        }
        i++;
    }
    printf("\n");
    return 0;
}