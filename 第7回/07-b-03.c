#include <stdio.h>
#include <stdlib.h>

int n, cost = 0, array[10];

void root_form_last(int index)
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
        root_form_last(index - 2);
        cost += diff_2;
    } else {
        root_form_last(index - 1);
        cost += diff_1;
    }
}

void root_form_first(int index)
{
    int diff_1, diff_2;
    diff_1 = abs(array[index] - array[index + 1]);
    diff_2 = abs(array[index] - array[index + 2]);
    if (index == n - 1) {
        return;
    }
    if (index == n - 2) {
        cost += diff_1;
        return;
    }
    if (diff_1 >= diff_2) {
        root_form_first(index + 2);
        cost += diff_2;
    } else {
        root_form_first(index + 1);
        cost += diff_1;
    }
}

int main()
{
    int i;
    printf("input N : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    root_form_last(n - 1);
    int cost_from_last = cost;
    cost = 0;
    root_form_first(0);
    int cost_from_front = cost;
    if (cost_from_front >= cost_from_last) {
        printf("Minimum cost is %d\n", cost_from_last);
    } else {
        printf("Minimum cost is %d\n", cost_from_front);
    }
    return 0;
}