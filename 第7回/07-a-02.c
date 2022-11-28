#include <stdio.h>

int greatest_common_divisor(int x, int y)
{
    if (x % y == 0) {
        return y;
    }
    return greatest_common_divisor(y, x % y);
}

int main()
{
    int x, y;
    printf("Input two integers : ");
    scanf("%d %d", &x, &y);
    printf("greatest common divisor is %d\n", greatest_common_divisor(x, y));
    return 0;
}