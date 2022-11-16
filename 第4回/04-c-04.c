#include <stdio.h>

char alpharev(char letter)
{
    if ('a' <= letter && letter <= 'z') {
        letter = letter - ('a' - 'A');
    } else if ('A' <= letter && letter <= 'Z') {
        letter = letter + ('a' - 'A');
    }
    return letter;
}

int main()
{
    int ctrl_d, i, j;
    char element, array[100];
    for (;;) {
        for (i = 0; ; i++) {
            scanf("%c", &element);
            array[i] = element;
            if ((int)element == 10) {
                break;
            }
        }
        for (j = 0; j < i; j++) {
            printf("%c", alpharev(array[j]));
        }
        printf("\n");
        if (scanf("%d", &ctrl_d) == -1) {
            break;
        }
    }
    
    return 0;
}
