#include <stdio.h>

int main()
{
    int i, prev_num, next_num, tmp;
    prev_num = 1;
    next_num = 1;
    for (i = 1; i <= 20; i++) {
        printf("fib[%d]: %d\n", i, prev_num);
        tmp = prev_num + next_num;
        prev_num = next_num;
        next_num = tmp;
    }
    return 0;
}