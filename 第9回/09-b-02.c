#include <stdio.h>

void find_zero(char *a, int n)
{
    int i;
    printf("Zero in ");
    for (i = 0; i <= n; i++) {
        if (a[i] == 48) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main()
{
    int i, c;
    char a[100];
    for (i = 0; (c = getchar()) != 10; i++) {
        a[i] =  c;
    }
    find_zero(a, i - 1);
    return 0;
}