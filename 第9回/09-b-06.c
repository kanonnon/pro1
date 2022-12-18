#include <stdio.h>

int main()
{
    int i, j, x, array[100], binary[32];
    long int decimal = 0, add;
    char element;
    
    printf("word = 0x");
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
    for (i = 0; decimal > 0; i++) {
        binary[i] = decimal % 2;
        decimal /= 2;
    }
    for (j = 0; j < i; j++) {
        if (binary[j] == 1) {
            printf("bit index = %d\n", j);
            return 0;
        }
    }
    printf("bit index = 32\n");
    return 0;
}