#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, numbers[5];
    printf("input 5 numbers: ");
    for (i = 0; i < 5; i++) {
        scanf("%d", &numbers[i]);
    }
    for (i = 4; i > -1; i--) {
        printf("%d", numbers[i]);
    }
    printf("\n");
    return 0;
}