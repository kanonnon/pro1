#include <stdio.h>
#include <stdlib.h>

int main()
{
    float salt, water;
    printf("Input weight of salt (g): ");
    scanf("%f", &salt);
    printf("Input weight of water (g): ");
    scanf("%f", &water);

    if ((water + salt) * 0.2628 >= salt) {
        printf("%f (g) of salt dissolves in %f (g) of water.\n", salt, water);
    } else {
        printf("%f (g) of salt does not dissolve in %f of water.\n", salt, water);
    }
    return 0;
}