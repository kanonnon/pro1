#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, array[4];
    scanf("%d", &n);
    if (-9999 <= n && n <= 9999) {
        if (n < 0) {
            printf("minus ");
        }
        if (n == 0) {
            printf("zero");
        }
        array[0] = abs(n) / 1000;
        array[1] = (abs(n) - 1000 * array[0]) / 100;
        array[2] = (abs(n) - 1000 * array[0] - 100 * array[1]) / 10;
        array[3] = abs(n) - 1000 * array[0] - 100 * array[1] - 10 * array[2];
        for (i = 0; i < 4; i++) {
            switch (array[i]) {
                case 0:
                    continue;
                    break;
                case 1:
                    if (i == 3) {
                        printf("ichi ");
                    }
                    break;
                case 2:
                    printf("ni ");
                    break;
                case 3:
                    printf("san ");
                    break;
                case 4:
                    printf("yon ");
                    break;
                case 5:
                    printf("go ");
                    break;
                case 6:
                    printf("roku ");
                    break;
                case 7:
                    printf("nana ");
                    break;
                case 8:
                    printf("hachi ");
                    break;
                case 9:
                    printf("kyu ");
                    break;
            }
            switch (i) {
                case 0:
                    printf("sen ");
                    break;
                case 1:
                    printf("hyaku ");
                    break;
                case 2:
                    printf("ju ");
                    break;
            }
        }
        printf("\n");
    } else {
        printf("Input range is -9999 to 9999\n");
    }
    return 0;
}