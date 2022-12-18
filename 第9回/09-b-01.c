#include <stdio.h>
int i, j;

// 標準入力から数字を読み込み、a00~a22 の順で数字を格納する
void get_arr3x3(int a[][3])
{
    for (j = 0; j < 3; j++) {
        for (i = 0; i < 3; i++) {
            scanf("%d", &(a[j][i]));
        }
    }
}

// a + b の結果をc に格納する
void sum_arr3x3(int a[][3], int b[][3], int c[][3])
{
    for (j = 0; j < 3; j++) {
        for (i = 0; i < 3; i++) {
            c[j][i] = a[j][i] + b[j][i];
        }
    }
}

// 3x3 行列を標準出力に表示する
void print_arr3x3(int a[][3])
{
    for (j = 0; j < 3; j++) {
        for (i = 0; i < 3; i++) {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }
}

int main()
{
    int a[3][3], b[3][3], c[3][3];
    get_arr3x3(a);
    printf("a\n");
    print_arr3x3(a);
    get_arr3x3(b);
    printf("b\n");
    print_arr3x3(b);
    sum_arr3x3(a, b, c);
    printf("a + b\n");
    print_arr3x3(c);
    return 0;
}