#include <stdio.h>
#include <string.h>
#define MAX_LINE 256

int mystrlen(char *s)
{
    int count = 0;
    while (*s != '\0') {
        count++;
        s++;
    }
    return count;
}

int main()
{
    char s[MAX_LINE];
    fgets(s, MAX_LINE, stdin);
    printf("Length(mystrlen): %d\n", mystrlen(s));
    printf("Length(strlen): %lu\n", strlen(s));
    return 0;
}