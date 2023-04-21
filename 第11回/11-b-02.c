#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp_input, *fp_output;
    char buffer[80];
    int i = 0, j, tmp, num[1000000];
    if ((fp_input = fopen("11-b-02.txt", "r")) == NULL) {
        exit(1);
    }
    if ((fp_output = fopen("11-b-02-output.txt", "w")) == NULL) {
        exit(1);
    }
    while (fgets(buffer, 80, fp_input) != NULL) {
        num[i] = atoi(buffer);
        i++;
    }
    for (i = 0; i < 1000000; i++) {
        for (j = i + 1; j < 1000000; j++) {
            if (num[i] > num[j]) {
                tmp =  num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
        }
    }
    for (i = 0; i < 1000000; i++) {
        snprintf(buffer, 80, "%d", num[i]);
        fputs(buffer, fp_output);
        fputs("\n", fp_output);
    }
    fclose(fp_input);
    fclose(fp_output);
    return 0;
}