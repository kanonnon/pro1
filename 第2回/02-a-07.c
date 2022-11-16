#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    printf("input an integer: ");
    scanf("%d", &number);

    if (0 < number && number < 10) {
        printf("%d is one disit positive integer.\n", number);
    } else {
        printf("%d is not one disit positive integer.\n", number);
    }
    return 0;
}