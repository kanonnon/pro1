#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    printf("Input number: ");
    scanf("%d", &number);
    printf("%d is...\n", number);

    if (number == 0) {
        printf("Input number is 0.");
    } else if (number > 0) {
        if (number % 2 == 0) {
            printf("Positive even number\n");
        } else{
            printf("Positive odd number\n");
        }
    } else {
        if (number % 2 == 0) {
            printf("Negative even number\n");
        } else{
            printf("Negative odd number\n");
        }
    }
}