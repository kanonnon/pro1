#include <stdio.h>
#include <string.h>
#define MAX_LEN 256

void mystrrev(char *s1, char *s2)
{
    while (*s2) {
        s2++;
    }
    s2 -= 2;
    while ((*s1++ = *s2--)) {
    }
}

int main()
{
    char s1[MAX_LEN], s2[MAX_LEN];
    fgets(s2, MAX_LEN, stdin);
    printf("[IN]%s", s2);
    mystrrev(s1, s2);
    printf("[REV]%s\n", s1);
    return 0;
}