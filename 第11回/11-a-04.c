#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *fp;
    int c, sentence = 0, word = 0;
    if ((fp = fopen("11-a-04.txt", "r")) == NULL) {
        exit(1);
    }
    while ((c = fgetc(fp)) != EOF) {
        if (c == 32) {
            word++;
        }
        if (c == 46) {
            sentence++;
        }
    }
    fclose(fp);
    printf("sentence : %d\n", sentence);
    printf("word : %d\n", word + 1);
    return 0;
}