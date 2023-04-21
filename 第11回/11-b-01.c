#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp1, *fp2;
    int ch = 0, c1, c2;
    char file1[20], file2[20];
    printf("File1 : ");
    scanf("%s", file1);
    printf("File2 : ");
    scanf("%s", file2);
    if ((fp1 = fopen(file1, "r")) == NULL) {
        exit(1);
    }
    if ((fp2 = fopen(file2, "r")) == NULL) {
        exit(1);
    }
    while (((c1 = fgetc(fp1)) != EOF) && ((c2 = fgetc(fp2)) != EOF)) {
        while (c1 == 10 || c1 == 32) {
            c1 = fgetc(fp1);
        }
        while (c2 == 10 || c2 == 32) {
            c2 = fgetc(fp2);
        }
        if (c1 != c2) {
            ch = 1;
            break;
        }
    }
    if (ch == 0) {
        printf("Equal\n");
    } else {
        printf("Not Equal\n");
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}