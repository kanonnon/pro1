#include <stdio.h>

int x = 0;

void assign(int a)
{
    x = a;
    printf("assigned.\n");
}

int main()
{
    int a;
    printf("input an integer :");
    scanf("%d", &a);
    printf("x :%d\n", x);
    assign(a);
    printf("x :%d\n", x);
    return 0;
}