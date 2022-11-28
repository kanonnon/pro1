#include <stdio.h>

void print_sequence(int n)
{
    if (n <= 0) {
        return;
    }
    print_sequence(n - 1);
    printf("%d ", n);
}

int main()
{
    int n;
    printf("input an integer : ");
    scanf("%d", &n);
    print_sequence(n);
    printf("\n");
    return 0;
}