#include <stdio.h>
#include <stdlib.h>

int main()
{
    int first, second;
    printf("Input 1st number: ");
    scanf("%d", &first);
    printf("Input 2nd number: ");
    scanf("%d", &second);

    if (first == second) {
        printf("Two numbers are equal.\n");
    } else {
        if (first > second) {
            printf("%d is larger than %d.\n", first, second);
        } else {
            printf("%d is larger than %d.\n", second, first);
        }
    }
    return 0;
}