#include <stdio.h>

int main()
{
    int c, i, j, k, binary[8];
    c = getchar();
    for (i = 0; c > 0; i++) {
        binary[i] = c % 2;
        c /= 2;
    }
    for (k = 8; k > i; k--) {
        printf("0");
    }
    for (j = i - 1; j > -1; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
    return 0;
}