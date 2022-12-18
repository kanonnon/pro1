#include <stdio.h>

#define N 10

void init_array(float f[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        f[i] = 0;
        printf("f[%d]:%f\n", i, f[i]);
    }
}

int main()
{
    float f[N];
    init_array(f, N);
    return 0;
}