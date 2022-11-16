#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, num, result;
    printf("input an integer: ");
    scanf("%d", &num);
    if (num < 0) {
        result = num * -1;
    } else {
        result = num;
    }
    if (num == 0) {
        printf("0 is a 1 digits number\n");
    } else {
        for (i = 0; result > 0; i++) {
            result /= 10;
        }
        printf("%d is a %d digits number\n", num, i);
    }
    return 0;
}