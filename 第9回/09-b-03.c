#include <stdio.h>

int main()
{
    int i, j, c, a[100];
    while (c != EOF) {
        for (i = 0; (c = getchar()) != 10; i++) {
            if (c == EOF) {
                break;
            }
            a[i] =  c;
        }
        for (j = 0; j < i; j++) {
            printf("%d\n", a[j]);
        }
    }
    return 0;
}