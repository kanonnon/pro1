#include <stdio.h>

int main()
{
    int i, j, c, status = 65, array[100];
    for (i = 1; (c = getchar()) != 10; i++) {
        array[i] = c;
    }
    printf("place[0] : %c\n", status);
    for (j = 1; j <= i; j++) {
        if (!(array[j] == 97 || array[j] == 98 || array[j] == 99)) {
            break;
        }
        switch(array[j]) {
        case 97:
            switch (status) {
            case 65:
            case 66:
                status += 1;
                break;
            case 67:
                status -= 2;
                break;
            }
            break;
        case 98:
            switch (status) {
            case 65:
                status += 2;
                break;
            case 66:
            case 67:
                status -= 1;
                break;
            }
            break;
        case 99:
            break;
        }
            
        printf("place[%d] : %c\n", j, status);
    }
    return 0;
}