#include <stdio.h>
#include <string.h>
#define MAX_LINE 32

int mystrstr(char *sentence, char *word)
{
    int i, j;
    for (i = 0; *(sentence + i) != '\0'; i++) {
        if (*(sentence + i) == *word) {
            for (j = 0; *(sentence + i) == *(word + j); i++, j++) {
                if (*(word + j + 1) == '\0') {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    char sentence[MAX_LINE], word[MAX_LINE], *p;
    printf("input a sentence: ");
    fgets(sentence, MAX_LINE, stdin);
    printf("input a word: ");
    fgets(word, MAX_LINE, stdin);
    p = strrchr(word, '\n');
    if (p != NULL) {
        *p = '\0';
    }
    if (mystrstr(sentence, word) == 1) {
        printf("The word (%s) exists\n", word);
    } else {
        printf("The word (%s) doesn't exist\n", word);
    }
    return 0;
}