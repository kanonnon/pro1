#include <stdio.h>

int counter(char c[], int n)
{
    int i, count = 0;
    for (i = 0; i < n; i++) {
        switch ((int)c[i]) {
            case 97:
            case 105:
            case 117:
            case 101:
            case 111:
                count++;
                break;
        }
    }
    return count;
}

int main()
{
    int i;
    char c[10];
    printf("input 10 characters : ");
    for (i = 0; i < 10; i++) {
        scanf("%c", &(c[i]));
    }
    printf("count: %d\n", counter(c, 10));
    return 0;
}