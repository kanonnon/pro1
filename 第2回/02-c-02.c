#include <stdio.h>
#include <stdlib.h>

int main()
{
    int first, second, third, tmp;
    printf("Input 1: ");
    scanf("%d", &first);
    printf("Input 2: ");
    scanf("%d", &second);
    printf("Input 3: ");
    scanf("%d", &third);

    if (first > third) {
        tmp = first;
        first = third;
        third = tmp;
    }
    if (first > second) {
        tmp = first;
        first = second;
        second = tmp;
    }
    if (second > third) {
        tmp = second;
        second = third;
        third = tmp;
    }

    printf("Sorted: %d, %d, %d\n", first, second, third);
}