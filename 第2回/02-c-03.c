#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    printf("input an integer: ");
    scanf("%d", &number);

    if (number % 2 == 0) {
        if (number % 3 == 0) {
            if (number % 5 == 0) {
                printf("%d is divisible by 2, 3 and 5.\n", number);
            } else {
                printf("%d is divisible by 2 and 3 but not divisible by 5.\n", number);
            }
        } else {
            if (number % 5 == 0) {
                printf("%d is divisible by 2 and 5 but not divisible by 3.\n", number);
            } else {
                printf("%d is divisible by 2 but not divisible by 3 nor 5.\n", number);
            }
        }
    } else {
        if (number % 3 == 0) {
            if (number % 5 == 0) {
                printf("%d is divisible by 3 and 5 but not divisible by 2.\n", number);
            } else {
                printf("%d is divisible by 3 but not divisible by 2 nor 5.\n", number);
            }
        } else {
            if (number % 5 == 0) {
                printf("%d is divisible by 5 but not divisible by 2 nor 3.\n", number);
            } else {
                printf("%d is not divisible by 2, 3 nor 5.\n", number);
            }
        }
    }
}