#include <stdio.h>

int change_style(int c)
{
    if (97 <= c && c <= 122) {
        c -= 32;
    } else if (65 <= c && c <= 90) {
        c += 32;
    }
    return c;
}

int main()
{
    int i, j, c, status, array[1000];
    while (1) {
        status = 1;
        for (i = 0; (c = getchar()) != 10; i++) {
            if (c == EOF) {
                return 0;
            }
            if (65 <= c && c <= 90) {
                if (status == 0) {
                    array[i] = change_style(c);
                } else {
                    array[i] = c;
                    status = 0;
                }
            } else if (97 <= c && c <= 122) {
                if (status == 0) {
                    array[i] = c;
                } else {
                    array[i] = change_style(c);
                    status = 0;
                }
            } else if (c == 32 || c == 44 || c == 46) {
                array[i] = c;
                status = 1;
            } else {
                array[i] = c;
            }
        }
        for (j = 0; j < i; j++) {
            printf("%c", array[j]);
        }
        printf("\n");
    }
    return 0;
}