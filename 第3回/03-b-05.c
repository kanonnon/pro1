#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, array[1000], count[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (i = 0;;i++) {
        scanf("%d", &array[i]);
        if (array[i]== 0) {
            break;
        } else if (array[i] < 0 || 9 < array[i]){
            printf("Illegal input: %d\n", array[i]);
            i--;
        }
    }
    for (j = 0; j < i; j++) {
        for (k = 0; k < 9; k++) {
            if (array[j] == k + 1) {
                count[k] += 1;
            }
        }
    }
    for (i = 0; i < 9; i++) {
        printf("[%d] : %d\n", i + 1 , count[i]);
    }
    return 0;
}