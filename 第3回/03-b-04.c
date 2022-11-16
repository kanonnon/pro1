#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array_size, i, array[1000], max, min, sum;
    printf("input array size: ");
    scanf("%d", &array_size);
    printf("input array elements: ");
    for (i = 0; i < array_size; i++) {
        scanf("%d", &array[i]);
    }
    max = array[0];
    min = array[0];
    sum = array[0];
    for (i = 1; i < array_size; i++) {
        if (max < array[i]) {
            max = array[i];
        }
        if (min > array[i]) {
            min = array[i];
        }
        sum += array[i];
    }
    printf("max: %d, min : %d, average : %f\n", max, min, (float)sum / array_size);
    return 0;
}