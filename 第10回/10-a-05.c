#include <stdio.h>
#include <string.h>
#define MAX_LINE 256

int main()
{
    char s1[MAX_LINE], s2[MAX_LINE], s3[MAX_LINE];
    int len1, len2, len3;
    printf("input a string (1) : ");
    fgets(s1, MAX_LINE, stdin);
    len1 = strlen(s1);
    printf("input a string (2) : ");
    fgets(s2, MAX_LINE, stdin);
    len2 = strlen(s2);
    printf("input a string (3) : ");
    fgets(s3, MAX_LINE, stdin);
    len3 = strlen(s3);

    if (len1 < len2 && len2 < len3) {
        printf("max : %s", s3);
    } else if (len1 < len2) {
        printf("max : %s", s2);
    } else {
        printf("max : %s", s1);
    }
    return 0;
}