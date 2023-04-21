#include <stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    float x, y;
    if (argc != 3) {
        printf("Error\n");
    } else {
        x = atof(argv[1]);
        y = atof(argv[2]);
        printf("%f + %f = %f\n", x, y, x + y);
        printf("%f - %f = %f\n", x, y, x - y);
        printf("%f * %f = %f\n", x, y, x * y);
        printf("%f / %f = %f\n", x, y, x / y);
    }
}