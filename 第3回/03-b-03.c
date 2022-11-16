#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, num, total;
    total = 0;
    printf("Please input number: ");
    scanf("%d", &num);
    if (1 <= num && num <= 100) {
        for (i = 1; i <= num; i++) {
            total += i;
        }
        printf("Sum 1 - %d is: %d\n", num, total);
    } else {
        printf("Error: input range is 1 to 100\n");
    }
    return 0;
}