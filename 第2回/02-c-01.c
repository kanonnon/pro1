#include <stdio.h>
#include <stdlib.h>

int main()
{
    float first, second, third, fourth, avarage, dispersion;
    printf("Input 1st number: ");
    scanf("%f", &first);
    printf("Input 2nd number: ");
    scanf("%f", &second);
    printf("Input 3rd number: ");
    scanf("%f", &third);
    printf("Input 4th number: ");
    scanf("%f", &fourth);

    avarage = (first + second + third + fourth) / 4;
    dispersion = ((first - avarage) * (first - avarage) + (second - avarage) * (second - avarage) + (third - avarage) * (third - avarage) + (fourth - avarage) * (fourth - avarage)) / 4;
    printf("Average: %f\n", avarage);
    printf("Dispersion: %f\n", dispersion);
}