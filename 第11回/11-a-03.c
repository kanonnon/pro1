#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *fp;
    char name[32];
    int c, height, weight;
    if ((fp = fopen("11-a-03.txt", "r")) == NULL) {
        exit(1);
    }
    while(fscanf(fp, "%s %d %d", name, &height, &weight) != EOF) {
        printf("name = %s, height = %d, weight = %d\n", name, height, weight);
    }
    fclose(fp);
    return 0;
}