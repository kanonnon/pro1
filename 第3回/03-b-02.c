#include <stdio.h>
#include <stdlib.h>

#define MAX_BIT 32

int main()
{
    int i, j, num, binary[MAX_BIT];
    printf("input a decimal number: ");
    scanf("%d", &num);
    for (i = 0; num > 0; i++) {
        binary[i] = num % 2;
        num /= 2;
    }
    for (j = i - 1; j > -1; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
    return 0;
}