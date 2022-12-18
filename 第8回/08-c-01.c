#include <stdio.h>

int main()
{
    int k, i, j, w, array[10][3];
    float x, y;
    printf("Input a,b,c\n");
    for (k = 0; k < 10; k++) {
        if (scanf("%d %d %d", &(array[k][0]), &(array[k][1]), &(array[k][2])) == EOF) {
            break;
        }
        if (array[k][0] == 0 || array[k][1] == 0) {
            printf("Illegal input\n");
            k--;
            continue;
        }
    }
    for (i = 0; i < k; i++) {
        for (j = 0; j < i; j++) {
            w = array[j][1] * array[i][0] - array[i][1] * array[j][0];
            if (w == 0) {
                continue;
            }
            x = (float)(array[j][1] * array[i][2] - array[i][1] * array[j][2]) / w;
            y = (array[i][2] - array[i][0] * x) / array[i][1];
            printf("(%f, %f)\n", x, y);
        }
    }
    return 0;
}