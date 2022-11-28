#include <stdio.h>
#include <stdlib.h>

int cost = 0, array[10];

void root(int index)
{
    int diff_1, diff_2;
    diff_1 = abs(array[index] - array[index - 1]);
    diff_2 = abs(array[index] - array[index - 2]);
    if (index == 0) {
        return;
    }
    if (index == 1) {
        cost += diff_1;
        return;
    }
    if (diff_1 >= diff_2) {
        root(index - 2);
        cost += diff_2;
    } else {
        root(index - 1);
        cost += diff_1;
    }
}

int main()
{
    int n, i;
    printf("input N : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    root(n - 1);
    printf("Minimum cost is %d\n", cost);
    return 0;
}