#include <stdio.h>

void mytoupper(char *p)
{
    if ('a' <= *p && *p <= 'z') {
        *p = *p - ('a' - 'A');
    }
    printf("Output character: %c\n", *p);
}

int main()
{
    char alphabet, *p;
    printf("Input character: ");
    scanf("%c", &alphabet);
    mytoupper(&alphabet);
    return 0;
}