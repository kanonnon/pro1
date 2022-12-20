#include <stdio.h>
#include <string.h>
#define MAX_LINE 256

int main()
{
    char s1[MAX_LINE], s2[MAX_LINE];
    fgets(s1, MAX_LINE, stdin);
    strncpy(s2, s1, 3);
    s2[3] = '\0';
    printf("%s\n", s2);
    return 0;
}