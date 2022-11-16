#include <stdio.h>
#include <stdlib.h>

int main()
{
    float first, second;
    int result;
    printf("Input 1st number: ");
    scanf("%f", &first);
    printf("Input 2nd number: ");
    scanf("%f", &second);
    result = first + second;
    printf("Result is: %d\n", result);
    return 0;
}