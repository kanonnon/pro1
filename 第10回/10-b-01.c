#include <stdio.h>
#include <string.h>
#define MAX_LEN 256

char *mystrcat(char *s1, char *s2)
{
    char *line = s1;
    while (*s1) {
        s1++;
    }
    while ((*s1++ = *s2++)) {
    }
    return line;
}

int main()
{
    char str1[MAX_LEN] = "abc", str2[] = "def";
    mystrcat(str1, str2);
    printf("%s\n", str1);
    return 0;
}