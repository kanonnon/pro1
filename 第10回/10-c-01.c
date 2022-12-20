#include <stdio.h>
#include <string.h>
#define MAX_LINE 32

int main()
{
    int i = 0;
    char word[20][MAX_LINE];
    while (word) {
        fgets(word[i], MAX_LINE, stdin);
    }
    return 0;
}