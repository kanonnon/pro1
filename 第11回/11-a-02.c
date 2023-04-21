#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *fp_input, *fp_output;
    char input[80], output[80], buffer[80];
    int i, num;
    printf("input filename : ");
    scanf("%s", input);
    printf("loop num : ");
    scanf("%d", &num);
    printf("output filename : ");
    scanf("%s", output);
    if ((fp_input = fopen(input, "r")) == NULL) {
        exit(1);
    }
    if ((fp_output = fopen(output, "a")) == NULL) {
        exit(1);
    }
    for (i = 0; i < num; i++) {
        while (fgets(buffer, 80, fp_input) != NULL) {
            fputs(buffer, fp_output);
        }
        fputs("\n", fp_output);
        fseek(fp_input, 0, SEEK_SET);
    }
    fclose(fp_input);
    fclose(fp_output);
    return 0;
}