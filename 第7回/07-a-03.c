#include <stdio.h>

int tousa(int a, int d, int n)
{
    if (n == 0) {
        return 0;
    }
    tousa(a, d, n - 1);
    printf("[%d] : %d\n", n, a + d * (n - 1));
    return 0;
}

int main()
{
    int a, d, n;
    printf("Input a d n : ");
    scanf("%d %d %d", &a, &d, &n);
    tousa(a, d, n);
    return 0;
}