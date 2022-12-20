#include <stdio.h>
#include <string.h>
#define MAX_LEN 256

void strrpt(char *s1, char *s2, int n)
{
    int i;
    char *start = s2;
    for (i = 0; i < n; i++) {
        s2 = start;
        while ((*s1++ = *s2++)) {
        }
        s1 -= 2;
    }
}

int main()
{
    int n;
    char s1[MAX_LEN], s2[MAX_LEN];
    printf("Input string: ");
    fgets(s2, MAX_LEN, stdin);
    printf("Input repeat time: ");
    scanf("%d", &n);
    printf("[ORG]%s", s2);
    strrpt(s1, s2, n);
    printf("[RPT]%s", s1);
    return 0;
}