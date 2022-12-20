#include <stdio.h>
#include <string.h>
#define MAX_LINE 256

void shift(char *s, int key)
{
    while (*s != '\0') {
        char *q;
        q = strrchr(s, '\n');
        if (q != NULL) {
            *q = '\0';
        }
        if (*s + key > 126) {
            *s = *s + key - 104 ;
        } else {
            *s = *s + key;
        }
        s++;
    }
}

int main()
{
    char line[MAX_LINE];
    int key;
    printf("input string : ");
    fgets(line, MAX_LINE, stdin);
    printf("input key : ");
    scanf("%d", &key);
    key %= 104;
    shift(line, key);
    printf("%s\n", line);
    return 0;
}