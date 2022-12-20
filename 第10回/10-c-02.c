#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 256

// 文字列sを引数にとり、これまでに与えられたs内部に含まれる数値の和を返す
double sumofstrnum(char *s)
{
    int i, j, status1 = 0, status2 = 1;
    double num_int;
    static int k = 0;
    static double sum = 0;
    char num[100][MAX_LINE];
    for (i = 0; *(s + i) != '\0'; i++, j++) {
        if (('0' <= *(s + i) && *(s + i) <= '9') || *(s + i) == '.' ||  *(s + i) == '-') {
            if (status1 == 0) {
                j = 0;
                k++;
                status2 = 0;
                *(num[k] + j) = *(s + i);
            } else {
                *(num[k] + j) = *(s + i);
            }
            status1 = 1;
        } else {
            if (status2 == 0) {
                num_int = strtod(num[k], NULL);
                sum += num_int;
            }
            status2 = 1;
            status1 = 0;
        }
    }
    if (status2 == 0) {
        num_int = strtod(num[k], NULL);
        sum += num_int;
    }
    return sum;
}

int main() { 
    printf("%lf\n", sumofstrnum("0011abc-20a2bc"));
    printf("%lf\n", sumofstrnum("123"));
    printf("%lf\n", sumofstrnum("aabbcca1b2b3"));
    printf("%lf\n", sumofstrnum("aabb1.2bb23.560"));
    printf("%lf\n", sumofstrnum("aabb-1.2bb-23.56p-"));
    printf("%lf\n", sumofstrnum("aabb-23s34ccs2.0"));
    return 0;
}
