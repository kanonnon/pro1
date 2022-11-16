#include <stdio.h>

int main()
{
    char element, array[1000];
    int i, j, sum = 0;

    for (i = 0; ; i++) {
        rewind(stdin);  // キーボードバッファをクリア
        scanf("%c", &element);
        if (('a' <= element && element <= 'z') || ('A' <= element && element <= 'Z')) {
            i--;
            if (element == 'E') {
                break;
            } else {
                printf("Illegal input: %c\n", element);
            }
        } else if ('0' <= element && element <= '9') {
            array[i] = element;
        }
    }
    
    for (j = 0; j <= i; j++) {
        sum += (array[j] - 48);
    }

    printf("Sum is: %d\n", sum);
    printf("Average is: %f\n", (float)sum / (i + 1));
    return 0;
}