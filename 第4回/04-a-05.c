#include <stdio.h>

int a = 500, b = 500;

void hundred1(int a)
{
    a = 100;
}

void hundred2(int *p)
{
    *p = 100;
}

int main()
{
    printf("before: a=%d, b=%d\n", a, b);
    hundred1(a);
    hundred2(&b);
    printf("after: a=%d, b=%d\n", a, b);
    return 0;
}