#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *fp;
    char buffer[80];
    if ((fp = fopen("11-a-01.txt", "w")) == NULL) {
        exit(1);
    }
    printf("Input student number : ");
    fgets(buffer, 80, stdin);
    fputs("ID = ", fp);
    fputs(buffer, fp);
    fseek(fp, -1, SEEK_END);
    printf("Input name : ");
    fgets(buffer, 80, stdin);
    fputs(", name = ", fp);
    fputs(buffer, fp);
    fclose(fp);
    return 0;
}