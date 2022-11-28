#include <stdio.h>

int culc_p(int m, int n)
{
    if (n == 0) {
        return 1;
    }
    return m * culc_p(m - 1, n - 1);
}

int culc_c(int m, int n)
{
    if (n == 0) {
        return 1;
    }
    return m * culc_c(m - 1, n - 1) / n;
}

int main()
{
    int m, n;
    printf("input m and n : ");
    scanf("%d %d", &m, &n);
    printf("%d P %d = %d\n", m, n, culc_p(m, n));
    printf("%d C %d = %d\n", m, n, culc_c(m, n));
    return 0;
}