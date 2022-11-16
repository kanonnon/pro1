#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, size;
    printf("input number: ");
    scanf("%d", &size);
    int pascal[size + 1][size + 1];

    // 数字を二次元配列に入れる
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (j == 0) {
                pascal[i][j] = 1;
            } else if (j == i) {
                pascal[i][j] = 1;
                break; 
            } else {
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
    }

    // 逆三角形に数字を書き出す
    for (i = size - 1; i >= 0; i--) {
        for (k = 0; k < size - i; k++) {
            printf("     ");
        }
        for (j = 0; j <= size; j++) {
            if (i == j) {
                printf("%5d", pascal[i][j]);
                break;
            } else {
                printf("%5d     ", pascal[i][j]);
            }
        }
        printf("\n");
    }

}