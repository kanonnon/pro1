#include <stdio.h>

int main()
{
    int i, j, decimal = 0, array[100], add, x;
    char element;
    
    printf("Input hexadecimal number: ");
    for (i = 0; ; i++) {
        scanf("%c", &element);
        if ('0' <= element && element <= '9') {
            array[i] = (int)element -  48;
        } else if ('a' <= element && element <= 'f') {
            array[i] = element - 87;
        } else {
            break;
        }
    }
    for (j = 0; j < i; j ++) {
        add = array[j];
        for (x = i - j - 1; x > 0; x--) {
            add *= 16;
        }
        decimal += add;
    }
    printf("Decimal number is %d\n", decimal);
    return 0;
}